#pragma once
#include "stdafx.h"

class Audio
{
public:
	Audio();
	~Audio();

	IXAudio2* xaudio2;	//XAudio2 엔진 인스턴스
	IXAudio2MasteringVoice* masterVoice;	//마스터 보이스
	IMFAttributes* sourceReaderConfiguration;

	bool Initialize();
	void Uninitialize();
	bool LoadFile(const wchar_t* path, std::vector<BYTE>& audioData, WAVEFORMATEX** waveFormatEx, unsigned int& waveLength);

	static Audio* GetInstance();

};