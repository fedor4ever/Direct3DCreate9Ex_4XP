// d3d9ex.dll.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <d3d9.h>
#include <iostream>
//#include <d3dx9.h>
#include "d3d9ex.h"

d3d9_dll d3d9;

typedef IDirect3D9 *(APIENTRY *tDirect3DCreate9)(UINT);

HRESULT D3D9EXDLL_API Direct3DCreate9Ex(
    UINT         SDKVersion, /*  [in] */
    IDirect3D9Ex **ppD3D     /*[out]*/
    )
{
	freopen("output.txt","a+",stdout);
	std::cout << "d3d9ex" ;
	std::cout << __LINE__ << "\n";
	IDirect3D9 *local = NULL; // =
        //(IDirect3D9Ex*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(IDirect3D9Ex));

	//tDirect3DCreate9 D3D = (tDirect3DCreate9)d3d9.Direct3DCreate9;
	tDirect3DCreate9 D3D = (tDirect3DCreate9)GetProcAddress(d3d9.dll, "Direct3DCreate9");
	MessageBox(NULL, L"Custom IDirect3D9Ex ready!", L"D3D9 Proxy DLL info", MB_OK);
	if( NULL == (local = (D3D)(D3D_SDK_VERSION)) )
        return E_OUTOFMEMORY;
    *ppD3D = dynamic_cast<IDirect3D9Ex*>(local);
	/*MessageBox(NULL, L"Custom IDirect3D9Ex ready!", L"D3D9 Proxy DLL info", MB_OK);*/
    return S_OK;
}

__declspec(naked) void Direct3DShaderValidatorCreate9(){
    _asm { jmp [d3d9.Direct3DShaderValidatorCreate9] }
}

__declspec(naked) void PSGPError(){
    _asm { jmp [d3d9.PSGPError] }
}

__declspec(naked) void PSGPSampleTexture(){
    _asm { jmp [d3d9.PSGPSampleTexture] }
}
__declspec(naked) void D3DPERF_BeginEvent(){
    _asm { jmp [d3d9.D3DPERF_BeginEvent] }
}

__declspec(naked) void _D3DPERF_EndEvent(){
    _asm { jmp [d3d9.D3DPERF_EndEvent] }
}

__declspec(naked) void _D3DPERF_GetStatus(){
    _asm { jmp [d3d9.D3DPERF_GetStatus] }
}
__declspec(naked) void _D3DPERF_QueryRepeatFrame(){
    _asm { jmp [d3d9.D3DPERF_QueryRepeatFrame] }
}

__declspec(naked) void D3DPERF_SetMarker(){
    _asm { jmp [d3d9.D3DPERF_SetMarker] }
}
__declspec(naked) void D3DPERF_SetOptions(){
    _asm { jmp [d3d9.D3DPERF_SetOptions] }
}

__declspec(naked) void D3DPERF_SetRegion(){
    _asm { jmp [d3d9.D3DPERF_SetRegion] }
}
__declspec(naked) void DebugSetLevel(){
    _asm { jmp [d3d9.DebugSetLevel] }
}
__declspec(naked) void DebugSetMute(){
    _asm { jmp [d3d9.DebugSetMute] }
}

__declspec(naked) void Direct3DCreate9(){
    _asm { jmp [d3d9.Direct3DCreate9] }
}


