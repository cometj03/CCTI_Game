#include "stdafx.h"
#include "SoundEvent.h"


SoundEvent::SoundEvent() :sourceVoice(nullptr)
{
	engine = Audio::GetInstance();
}

SoundEvent::SoundEvent(const wchar_t* path)
{
	SoundEvent();
	LoadFile(path);
}


SoundEvent::~SoundEvent()
{
}

void SoundEvent::LoadFile(const wchar_t* path)
{
	HRESULT hr = S_OK;

	// load file into wave
	WAVEFORMATEX* waveFormatEx;
	if (!engine->LoadFile(path, audioData, &waveFormatEx, waveLength))
	{
		return;
	}

	waveFormat = waveFormatEx;

	// create source voice
	//hr = engine->xaudio2->CreateSourceVoice(&soundEvent->sourceVoice, &soundEvent->waveFormat);
	if (FAILED(hr = engine->xaudio2->CreateSourceVoice(&sourceVoice, waveFormatEx)))
	{
		wprintf(L"Error %#X creating source voice\n", hr);
		return;
	}

	ZeroMemory(&audioBuffer, sizeof(XAUDIO2_BUFFER));
	audioBuffer.AudioBytes = (UINT32)audioData.size();
	audioBuffer.pAudioData = (BYTE * const)& audioData[0];
	audioBuffer.pContext = nullptr;

	audioPath = path;
}

void SoundEvent::Play()
{
	if (!sourceVoice)
	{
		printf("오디오 파일이 로드되지 않았습니다.\n");
		return;
	}
	// handle errors
	HRESULT hr = S_OK;

	// submit the audio buffer to the source voice
	hr = sourceVoice->SubmitSourceBuffer(&audioBuffer);
	if (FAILED(hr))
		puts("소스 버퍼에 접근이 불가능합니다.");

	// start the source voice
	sourceVoice->Start();
}

void SoundEvent::Stop()
{
	if (!sourceVoice)
	{
		printf("오디오 파일이 로드되지 않았습니다.\n");
		return;
	}
	sourceVoice->Stop();
	sourceVoice->FlushSourceBuffers();
}

void SoundEvent::Pause()
{
	if (!sourceVoice)
	{
		printf("오디오 파일이 로드되지 않았습니다.\n");
		return;
	}
	sourceVoice->Stop();
}
