#pragma once
#define EFIERR(a)           (0x80000000 | a)
#define EFI_SUCCESS 0
#define EFI_LOAD_ERROR EFIERR 1
#define EFI_INVALID_PARAMETER 2
#define EFI_UNSUPPORTED 3
#define EFI_BUFFER_TOO_SMALL 5
#define EFI_NOT_READY 6
#define EFI_NOT_FOUND 14

//Basic Types
#define BOOLEAN unsigned char
#define INTN int
#define UINTN unsigned int
#define INT8 char
#define UINT8 unsigned char
#define INT16 short
#define UINT16 unsigned short
#define INT32 int
#define UINT32 unsigned int
#define INT64 long long int
#define UINT64 unsigned long long int
#define INT128 __int128
#define UINT128 unsigned __int128
#define CHAR8 char
#define CHAR16 UINT16
#define VOID void
#define CONST const
#define cdecl
#define EFIAPI

//These are null to make it easier to c/p function prototypes
#define IN
#define OUT
#define OPTIONAL

typedef struct _EFI_GUID
{
	UINT32  Data1;
	UINT16  Data2;
	UINT16  Data3;
	UINT8   Data4[8];
} __attribute__((aligned(16))) EFI_GUID;

#define EFI_STATUS UINTN
#define EFI_HANDLE void*
#define EFI_EVENT void*
#define EFI_LBA UINT64
#define EFI_TPL UINTN
//

//Networking
struct EFI_MAC_ADDRESS
{
	CHAR8 Addr[32];
}__attribute__((packed));

struct EFI_IPv4_ADDRESS
{
	CHAR8 Addr[4];
}__attribute__((packed));

struct EFI_IPv6_ADDRESS
{
	CHAR8 Addr[16];
}__attribute__((packed));

struct EFI_IP_ADDRESS
{
	CHAR8 One[4];
	CHAR8 Two[4];
	CHAR8 Three[4];
	CHAR8 Four[4];
}__attribute__((packed));
//

//Memory
#define EFI_MEMORY_UC            0x0000000000000001
#define EFI_MEMORY_WC            0x0000000000000002
#define EFI_MEMORY_WT            0x0000000000000004
#define EFI_MEMORY_WB            0x0000000000000008
#define EFI_MEMORY_UCE           0x0000000000000010
#define EFI_MEMORY_WP            0x0000000000001000
#define EFI_MEMORY_RP            0x0000000000002000
#define EFI_MEMORY_XP            0x0000000000004000
#define EFI_MEMORY_NV            0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO            0x0000000000020000
#define EFI_MEMORY_SP            0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO    0x0000000000080000
#define EFI_MEMORY_RUNTIME       0x8000000000000000

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef enum
{
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef enum
{
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef struct
{
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS   PhysicalStart;
	EFI_VIRTUAL_ADDRESS	   VirtualStart;
	UINT64                 NumberOfPages;
	UINT64                 Attribute;
} EFI_MEMORY_DESCRIPTOR;


//

typedef struct
{
	long long Signature;
	unsigned int Revision;
	unsigned int HeaderSize;
	unsigned int CRC32;
	unsigned int Reserved;
} EFI_TABLE_HEADER;

typedef struct
{
	EFI_GUID VendorGuid;
	VOID* VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef enum { EFI_NATIVE_INTERFACE } EFI_INTERFACE_TYPE;
typedef enum { AllHandles, ByRegisterNotify, ByProtocol } EFI_LOCATE_SEARCH_TYPE;
typedef struct { EFI_HANDLE       AgentHandle; EFI_HANDLE       ControllerHandle; UINT32           Attributes; UINT32           OpenCount; } EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;
typedef struct _EFI_DEVICE_PATH_PROTOCOL { UINT8 Type; UINT8 SubType; UINT8 Length[2]; } EFI_DEVICE_PATH_PROTOCOL;

//Time
typedef enum { TimerCancel, TimerPeriodic, TimerRelative } EFI_TIMER_DELAY;

typedef struct
{
	UINT16   Year;              // 1900 � 9999
	UINT8   Month;              // 1 � 12
	UINT8   Day;                // 1 � 31
	UINT8   Hour;               // 0 � 23
	UINT8   Minute;             // 0 � 59
	UINT8   Second;             // 0 � 59
	UINT8   Pad1;
	UINT32   Nanosecond;  // 0 � 999,999,999
	INT16   TimeZone;           // -1440 to 1440 or 2047
	UINT8   Daylight;
	UINT8   Pad2;
} EFI_TIME;

typedef struct
{
	UINT32   Resolution;
	UINT32   Accuracy;
	BOOLEAN  SetsToZero;
} EFI_TIME_CAPABILITIES;

//idk
typedef struct { UINT64                   Length; union { EFI_PHYSICAL_ADDRESS   DataBlock;   EFI_PHYSICAL_ADDRESS   ContinuationPointer; }Union; } EFI_CAPSULE_BLOCK_DESCRIPTOR;
typedef enum { EfiResetCold, EfiResetWarm, EfiResetShutdown, EfiResetPlatformSpecific } EFI_RESET_TYPE;
typedef struct { EFI_GUID   CapsuleGuid; UINT32     HeaderSize; UINT32     Flags; UINT32     CapsuleImageSize; } EFI_CAPSULE_HEADER;
