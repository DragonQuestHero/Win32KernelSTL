#include "CRT/Ntddk.hpp"
#undef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 0
#include <string>


void DriverUnload(PDRIVER_OBJECT drive_object)
{
	DbgPrint("Unload Over!\n");
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT drive_object, PUNICODE_STRING path)
{
	drive_object->DriverUnload = DriverUnload;

	std::string a = "1";
	int b = std::stoi(a);
	DbgPrint("%s", a.data());


	return STATUS_SUCCESS;
}