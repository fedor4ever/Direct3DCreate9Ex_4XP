// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <iostream>
#include "d3d9ex.h"

extern d3d9_dll d3d9;

TCHAR dlldir[MAX_PATH];
TCHAR syspath[MAX_PATH];

HINSTANCE hlThis = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
        DWORD  reason,
        LPVOID lpReserved
		)
{
	//freopen("output.txt","a+", stdout);
	//std::cout << "in DllMain()" << "\n";
	//MessageBox(NULL, L"Custom d3d9.dll loaded!", L"D3D9 Proxy DLL info", MB_OK);
	//Sleep(3000);
#ifdef _DEBUG
	HANDLE h;
#endif
	hlThis = hModule;

	if(reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		//Get path to the original d3d9.dll
		char infoBuf[MAX_PATH];
		GetSystemDirectory(syspath, MAX_PATH);
		wcscat_s(syspath, L"\\d3d9.dll");

				//And load it...
		d3d9.dll = LoadLibrary(syspath);
		if (!d3d9.dll){
			MessageBox(NULL, L"D3D9 Proxy DLL error", L"Cannot find original d3d9.dll in the system directory!", MB_OK | MB_ICONERROR);
			return FALSE;
		}

		d3d9.D3DPERF_BeginEvent = GetProcAddress(d3d9.dll, "D3DPERF_BeginEvent");
		d3d9.D3DPERF_EndEvent = GetProcAddress(d3d9.dll, "D3DPERF_EndEvent");
		d3d9.D3DPERF_GetStatus = GetProcAddress(d3d9.dll, "D3DPERF_GetStatus");
		d3d9.D3DPERF_QueryRepeatFrame = GetProcAddress(d3d9.dll, "D3DPERF_QueryRepeatFrame");
		d3d9.D3DPERF_SetMarker = GetProcAddress(d3d9.dll, "D3DPERF_SetMarker");
		d3d9.D3DPERF_SetOptions = GetProcAddress(d3d9.dll, "D3DPERF_SetOptions");
		d3d9.D3DPERF_SetRegion = GetProcAddress(d3d9.dll, "D3DPERF_SetRegion");
		d3d9.DebugSetLevel = GetProcAddress(d3d9.dll, "DebugSetLevel");
		d3d9.DebugSetMute = GetProcAddress(d3d9.dll, "DebugSetMute");
		d3d9.Direct3DCreate9 = GetProcAddress(d3d9.dll, "Direct3DCreate9");
		d3d9.Direct3DShaderValidatorCreate9 = GetProcAddress(d3d9.dll, "Direct3DShaderValidatorCreate9");
		d3d9.PSGPError = GetProcAddress(d3d9.dll, "PSGPError");
		d3d9.PSGPSampleTexture = GetProcAddress(d3d9.dll, "PSGPSampleTexture");
	}else if(reason == DLL_PROCESS_DETACH)
	{
		FreeLibrary(d3d9.dll);
	}

	return TRUE;
}

