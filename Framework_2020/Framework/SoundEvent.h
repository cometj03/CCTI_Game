#pragma once
#include "stdafx.h"
#include "Audio.h"
class SoundEvent
{
private:
	IXAudio2SourceVoice* sourceVoice;	// the XAudio2 source voice
	WAVEFORMATEX* waveFormat;			// the format of the audio file
	unsigned int waveLength;			// the length of the wave
	std::vector<BYTE> audioData;		// the audio data
	XAUDIO2_BUFFER audioBuffer;			// the actual buffer with the audio data

	float fallof;						// falloff distance
	unsigned int priority;				// music priority

	unsigned int index;					// the index of the actual sound to play

	Audio* engine;
public:
	const wchar_t* audioPath;			//로드한 사운드파일의 경로 문자열을 저장합니다.
public:
	SoundEvent();						//SoundEvent객체 생성
	SoundEvent(const wchar_t* path);	//객체 생성과 동시에 사운드를 로드합니다.
	~SoundEvent();

public:
	//사운드파일을 로드합니다. 직접 값을 해석해 올라오기 때문에 Debug 상태에서의 로드 속도가 매우 느릴 수 있습니다.
	//Release로 변경할 경우 속도가 개선됩니다.
	void LoadFile(const wchar_t* path);

	//음악 재생, 멈춤, 일시정지
	void Play();
	void Stop();
	void Pause();
};

