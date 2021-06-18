#include "Main.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) {


	ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ݒ�

	if (DxLib_Init() == -1)	return -1;	//DX���C�u��������������

	Main main;
	//�Q�[���̊��ݒ�
	if (main.init() == false) {
		return -1;
	}

	//����ʂ�\��ʂɔ��f�A���b�Z�[�W�����A��ʃN���A
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//��ʂ̏��
		switch (main.status) {
		//���C�����
		case Main::Status::main:
			
			break;
		}
	}

	DxLib_End();		//DX���C�u�����g�p�̏I������

	return 0;			//�\�t�g�̏I��
}

//������(DX���C�u�����Ɖ�ʂ̊�{�ݒ�)
bool Main::init()
{
	//�^�C�g��
	SetMainWindowText("U22");
	status = Status::main;

	//Window�T�C�Y�̐ݒ�
	SetGraphMode(800, 600, 16);

	//Window���[�h�ύX�Ə�����
	ChangeWindowMode(TRUE);
	if (DxLib_Init() != 0) {
		return false;
	}
	//����ʐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//img�ǂݍ���

	return true;
}