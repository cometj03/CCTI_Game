#pragma once
#include "stdafx.h"

//Xaudio2를 사용하는 오디오 엔진 클래스입니다.
//기본적으로 오디오를 사용하기 위한 설정, 환경을 담당합니다.
//실제 사운드 로드, 재생은 SoundEvent 클래스를 통해 이뤄집니다.
class Audio
{
public:
	Audio();
	~Audio();

	IXAudio2* xaudio2;						//XAudio2 엔진 인스턴스
	IXAudio2MasteringVoice* masterVoice;	//마스터 보이스
	IMFAttributes* sourceReaderConfiguration;

	//초기화, 해제
	bool Initialize();
	void Uninitialize();

	//오디오 파일 로드
	//mp3, wav등의 파일을 Wav 파일 형식으로 변환하여 사용됩니다.
	bool LoadFile(const wchar_t* path, std::vector<BYTE>& audioData, WAVEFORMATEX** waveFormatEx, unsigned int& waveLength);

	//싱글턴 패턴
	//게임 내 오디오 객체를 받아옵니다.
	static Audio* GetInstance();
};