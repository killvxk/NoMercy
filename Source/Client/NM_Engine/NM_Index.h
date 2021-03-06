#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../NM_ClientSDK/NoMercy.h"

class CNoMercy
{
	public:
		// Initilization
		void InitTest(bool bClient); // Test only, Standalone app
		bool InitCore(const char* c_szLicenseCode, LPCVOID c_pModuleInfo, bool bStandaloneProcess); // Client, Core wrapper from SDK/DLL
		bool InitMasterServer(WORD wPort); // Master Server
		bool InitLauncher(const char* c_szLicenseCode, bool bProtected); // Launcher
		bool InitService(bool bProtected); // Service
		bool InitShadow(HMODULE hModule, HWND hWnd, HINSTANCE hInstance, LPSTR lpszCmdLine, int nCmdShow); // Shadow app(aka. rundll)
		bool InitHelper(); // Helper app

		// Finalization
		bool Release();

		// Utils
		bool CreateMessageHandler(TNMCallback lpMessageHandler);
		bool SendNMMessage(int Code, const void* lpMessage);

		void OnGameTick();
};

