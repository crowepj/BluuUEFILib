#pragma once
#include "EFI_TYPES.H"
#define EVT_TIMER                          0x80000000
#define EVT_RUNTIME                        0x40000000
#define EVT_NOTIFY_WAIT                    0x00000100
#define EVT_NOTIFY_SIGNAL                  0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES      0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE  0x60000202

#define TPL_APPLICATION    4
#define TPL_CALLBACK       8
#define TPL_NOTIFY         16
#define TPL_HIGH_LEVEL     31

typedef VOID(EFIAPI* EFI_EVENT_NOTIFY) (IN EFI_EVENT Event, IN VOID* Context);

typedef EFI_TPL(EFIAPI* EFI_RAISE_TPL) (IN EFI_TPL NewTpl);
typedef VOID(EFIAPI* EFI_RESTORE_TPL) (IN EFI_TPL OldTpl);
typedef EFI_STATUS(EFIAPI* EFI_ALLOCATE_PAGES) (IN EFI_ALLOCATE_TYPE        Type, IN EFI_MEMORY_TYPE          MemoryType, IN UINTN                    Pages, IN OUT EFI_PHYSICAL_ADDRESS* Memory);
typedef EFI_STATUS(EFIAPI* EFI_FREE_PAGES) (IN EFI_PHYSICAL_ADDRESS Memory, IN UINTN Pages);
typedef EFI_STATUS(EFIAPI* EFI_GET_MEMORY_MAP) (IN OUT UINTN* MemoryMapSize, OUT EFI_MEMORY_DESCRIPTOR* MemoryMap, OUT UINTN* MapKey, OUT UINTN* DescriptorSize, OUT UINT32* DescriptorVersion);
typedef EFI_STATUS(EFIAPI* EFI_ALLOCATE_POOL) (IN EFI_MEMORY_TYPE   PoolType, IN UINTN             Size, OUT VOID** Buffer);
typedef EFI_STATUS(EFIAPI* EFI_FREE_POOL) (IN VOID* Buffer);
typedef EFI_STATUS(EFIAPI* EFI_CREATE_EVENT) (IN UINT32             Type, IN EFI_TPL            NotifyTpl, IN EFI_EVENT_NOTIFY   NotifyFunction, OPTIONAL   IN VOID* NotifyContext, OPTIONAL   OUT EFI_EVENT* Event);
typedef EFI_STATUS(EFIAPI* EFI_SET_TIMER) (IN EFI_EVENT           Event, IN EFI_TIMER_DELAY     Type, IN UINT64              TriggerTime);
typedef EFI_STATUS(EFIAPI* EFI_WAIT_FOR_EVENT) (IN UINTN       NumberOfEvents, IN EFI_EVENT* Event, OUT UINTN* Index);
typedef EFI_STATUS(EFIAPI* EFI_SIGNAL_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_CLOSE_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_CHECK_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_PROTOCOL_INTERFACE) (IN OUT EFI_HANDLE* Handle, IN EFI_GUID* Protocol, IN EFI_INTERFACE_TYPE InterfaceType, IN VOID* Interface);
typedef EFI_STATUS(EFIAPI* EFI_REINSTALL_PROTOCOL_INTERFACE) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, IN VOID* OldInterface, IN VOID* NewInterface);
typedef EFI_STATUS(EFIAPI* EFI_UNINSTALL_PROTOCOL_INTERFACE) (IN EFI_HANDLE    Handle, IN EFI_GUID* Protocol, IN VOID* Interface);
typedef EFI_STATUS(EFIAPI* EFI_HANDLE_PROTOCOL) (IN EFI_HANDLE    Handle, IN EFI_GUID* Protocol, OUT VOID** Interface);
typedef EFI_STATUS(EFIAPI* EFI_REGISTER_PROTOCOL_NOTIFY) (IN EFI_GUID* Protocol, IN EFI_EVENT Event, OUT VOID** Registration);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_HANDLE) (IN EFI_LOCATE_SEARCH_TYPE  SearchType, IN EFI_GUID* Protocol OPTIONAL, IN VOID* SearchKey OPTIONAL, IN OUT UINTN* BufferSize, OUT EFI_HANDLE* Buffer);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_DEVICE_PATH) (IN EFI_GUID* Protocol, IN OUT EFI_DEVICE_PATH_PROTOCOL** DevicePath, OUT EFI_HANDLE* Device);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_CONFIGURATION_TABLE) (IN EFI_GUID* Guid, IN VOID* Table);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_LOAD) (IN BOOLEAN                    BootPolicy, IN EFI_HANDLE                 ParentImageHandle, IN EFI_DEVICE_PATH_PROTOCOL* DevicePath, IN VOID* SourceBuffer OPTIONAL, IN UINTN                      SourceSize, OUT EFI_HANDLE* ImageHandle);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_START) (IN EFI_HANDLE       ImageHandle, OUT UINTN* ExitDataSize, OUT CHAR16** ExitData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_EXIT) (IN EFI_HANDLE       ImageHandle, IN EFI_STATUS       ExitStatus, IN UINTN            ExitDataSize, IN CHAR16* ExitDataOPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_UNLOAD) (IN EFI_HANDLE  ImageHandle);
typedef EFI_STATUS(EFIAPI* EFI_EXIT_BOOT_SERVICES) (IN EFI_HANDLE ImageHandle, IN UINTN MapKey);

typedef EFI_STATUS(EFIAPI* EFI_GET_NEXT_MONOTONIC_COUNT) (OUT UINT64* Count);
typedef EFI_STATUS(EFIAPI* EFI_STALL) (IN UINTN  Microseconds);
typedef EFI_STATUS(EFIAPI* EFI_SET_WATCHDOG_TIMER) (IN UINTN        Timeout, IN UINT64       WatchdogCode, IN UINTN        DataSize, IN CHAR16* WatchdogData  OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_CONNECT_CONTROLLER) (IN EFI_HANDLE                ControllerHandle, IN EFI_HANDLE* DriverImageHandle  OPTIONAL, IN EFI_DEVICE_PATH_PROTOCOL* RemainingDevicePath OPTIONAL, IN BOOLEAN                   Recursive);
typedef EFI_STATUS(EFIAPI* EFI_DISCONNECT_CONTROLLER) (IN EFI_HANDLE ControllerHandle, IN EFI_HANDLE DriverImageHandle OPTIONAL, IN EFI_HANDLE ChildHandle    OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_OPEN_PROTOCOL) (IN EFI_HANDLE      Handle, IN EFI_GUID* Protocol, OUT VOID** Interface OPTIONAL, IN EFI_HANDLE      AgentHandle, IN EFI_HANDLE      ControllerHandle, IN UINT32          Attributes);
typedef EFI_STATUS(EFIAPI* EFI_CLOSE_PROTOCOL) (IN EFI_HANDLE      Handle, IN EFI_GUID* Protocol, IN EFI_HANDLE      AgentHandle, IN EFI_HANDLE      ControllerHandle);
typedef EFI_STATUS(EFIAPI* EFI_OPEN_PROTOCOL_INFORMATION) (IN EFI_HANDLE                            Handle, IN EFI_GUID* Protocol, OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY** EntryBuffer, OUT UINTN* EntryCount);
typedef EFI_STATUS(EFIAPI* EFI_PROTOCOLS_PER_HANDLE) (IN EFI_HANDLE Handle, OUT EFI_GUID*** ProtocolBuffer, OUT UINTN* ProtocolBufferCount);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_HANDLE_BUFFER) (IN EFI_LOCATE_SEARCH_TYPE  SearchType, IN EFI_GUID* Protocol OPTIONAL, IN VOID* SearchKeyOPTIONAL, OUT UINTN* NoHandles, OUT EFI_HANDLE** Buffer);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_PROTOCOL) (IN EFI_GUID* Protocol, IN VOID* Registration OPTIONAL, OUT VOID** Interface);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (IN OUT EFI_HANDLE* Handle, ...);
typedef EFI_STATUS(EFIAPI* EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (IN EFI_HANDLE Handle, ...);
typedef EFI_STATUS(EFIAPI* EFI_CALCULATE_CRC32)(IN VOID* Data, IN UINTN    DataSize, OUT UINT32* Crc32);
typedef VOID(EFIAPI* EFI_COPY_MEM) (IN VOID* Destination, IN VOID* Source, IN UINTN     Length);
typedef VOID(EFIAPI* EFI_SET_MEM) (IN VOID* Buffer, IN UINTN     Size, IN UINT8     Value);
typedef EFI_STATUS(EFIAPI* EFI_CREATE_EVENT_EX) (IN UINT32    Type, IN EFI_TPL NotifyTpl, IN EFI_EVENT_NOTIFY   NotifyFunction OPTIONAL, IN CONST VOID* NotifyContextOPTIONAL, IN CONST EFI_GUID* EventGroupOPTIONAL, OUT EFI_EVENT* Event);

typedef struct BootServices
{
	EFI_TABLE_HEADER         Hdr; 
	// // Task Priority Services // 
	EFI_RAISE_TPL RaiseTPL; // EFI 1.0+
	EFI_RESTORE_TPL RestoreTPL;   // EFI 1.0+// 
	// Memory Services // 
	EFI_ALLOCATE_PAGES AllocatePages; // EFI 1.0+ 
	EFI_FREE_PAGES FreePages;   // EFI 1.0+ 
	EFI_GET_MEMORY_MAP GetMemoryMap;   // EFI 1.0+ 
	EFI_ALLOCATE_POOL AllocatePool;  // EFI 1.0+ 
	EFI_FREE_POOL FreePool;  // EFI 1.0+
	// // Event & Timer Services // 
	EFI_CREATE_EVENT CreateEvent; // EFI 1.0+
	EFI_SET_TIMER SetTimer; // EFI 1.0+
	EFI_WAIT_FOR_EVENT WaitForEvent; // EFI 1.0+ 
	EFI_SIGNAL_EVENT SignalEvent; // EFI 1.0+ 
	EFI_CLOSE_EVENT CloseEvent; // EFI 1.0+ 
	EFI_CHECK_EVENT CheckEvent; // EFI 1.0+
	// // Protocol Handler Services //
	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;// EFI 1.0+
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface; // EFI 1.0+
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface; // EFI 1.0+  
	EFI_HANDLE_PROTOCOL HandleProtocol;// EFI 1.0+
	VOID*              Reserved; // EFI 1.0+
	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify; // EFI 1.0+
	EFI_LOCATE_HANDLE LocateHandle; // EFI 1.0+ 
	EFI_LOCATE_DEVICE_PATH LocateDevicePath;// EFI 1.0+ 
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable; // EFI 1.0+ //
	// Image Services // 
	EFI_IMAGE_LOAD LoadImage;// EFI 1.0+ 
	EFI_IMAGE_START StartImage;// EFI 1.0+

	EFI_EXIT Exit; // EFI 1.0+ 
	EFI_IMAGE_UNLOAD UnloadImage;// EFI 1.0+ 
	EFI_EXIT_BOOT_SERVICES ExitBootServices; // EFI 1.0+ 
	// // Miscellaneous Services // 
	EFI_GET_NEXT_MONOTONIC_COUNT    GetNextMonotonicCount; // EFI 1.0+
	EFI_STALL Stall;// EFI 1.0+
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer; // EFI 1.0+//
	// DriverSupport Services // 
	EFI_CONNECT_CONTROLLER ConnectController;// EFI 1.1 
	EFI_DISCONNECT_CONTROLLER DisconnectController;// EFI 1.1+ 
	// // Open and Close Protocol Services //
	EFI_OPEN_PROTOCOL OpenProtocol; // EFI 1.1+ 
	EFI_CLOSE_PROTOCOL CloseProtocol; // EFI 1.1+ 
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation; // EFI 1.1+ 
														   // // Library Services // 
	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;// EFI 1.1+ 
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;// EFI 1.1+
	EFI_LOCATE_PROTOCOL LocateProtocol;// EFI 1.1+
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES                   InstallMultipleProtocolInterfaces;  // EFI 1.1+
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES                   UninstallMultipleProtocolInterfaces;// EFI 1.1+// 
																									 // 32-bit CRC Services // 
	EFI_CALCULATE_CRC32 CalculateCrc32;// EFI 1.1+
	// // Miscellaneous Services// 
	EFI_COPY_MEM CopyMem;      // EFI 1.1+ 
	EFI_SET_MEM SetMem;

	EFI_CREATE_EVENT_EX CreateEventEx;
} EFI_BOOT_SERVICES;