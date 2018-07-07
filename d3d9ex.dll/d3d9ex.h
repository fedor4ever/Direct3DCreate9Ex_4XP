// Приведенный ниже блок ifdef - это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа D3D9EXDLL_EXPORTS,
// в командной строке. Этот символ не должен быть определен в каком-либо проекте
// использующем данную DLL. Благодаря этому любой другой проект, чьи исходные файлы включают данный файл, видит
// функции D3D9EXDLL_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef D3D9EXDLL_EXPORTS
#define D3D9EXDLL_API __stdcall
#else
#define D3D9EXDLL_API __stdcall
#endif

struct IDirect3D9Ex;

struct d3d9_dll
{
	HMODULE dll;

	FARPROC	Direct3DShaderValidatorCreate9;
    FARPROC	PSGPError;
    FARPROC	PSGPSampleTexture;
    FARPROC	D3DPERF_BeginEvent;
    FARPROC	D3DPERF_EndEvent;
    FARPROC	D3DPERF_GetStatus;
    FARPROC	D3DPERF_QueryRepeatFrame;
    FARPROC	D3DPERF_SetMarker;
    FARPROC	D3DPERF_SetOptions;
    FARPROC	D3DPERF_SetRegion;
    FARPROC	DebugSetLevel;
    FARPROC	DebugSetMute;
    FARPROC	Direct3DCreate9;
};

HRESULT D3D9EXDLL_API Direct3DCreate9Ex(
    UINT         SDKVersion, /*  [in] */
    IDirect3D9Ex **ppD3D     /*[out]*/
    );
