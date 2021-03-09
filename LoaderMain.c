#include "BluuUEFI/EFI_SYSTEM_TABLE.h"
#include "BluuUEFI/EFI_GRAPHICS_OUTPUT_PROTOCOL.h"
#include "KernelStartupInfo.h"

extern void KernelMain(EFI_GRAPHICS_OUTPUT_PROTOCOL* gop);

EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* ST)
{
	EFI_GRAPHICS_OUTPUT_PROTOCOL* GOP;
	EFI_GUID GOP_GUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

	ST->BootServices->LocateProtocol(&GOP_GUID, 0, (VOID**)&GOP);

	KernelMain(GOP);

	return EFI_SUCCESS;
}