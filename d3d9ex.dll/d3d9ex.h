// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ���������
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� D3D9EXDLL_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, �����
// ������� D3D9EXDLL_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
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
