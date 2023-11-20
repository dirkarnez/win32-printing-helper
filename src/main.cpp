#define UNICODE
#define _UNICODE
#include <iostream>
#include <memory>
#include <windows.h>



int main()
{
  wchar_t pname[256];
  DWORD dwSize = 256;

  DWORD dwNeeded, dwReturned;
  PRINTER_INFO_5W* pinfo;

  GetDefaultPrinterW(pname, &dwSize);

  std::wstring default_printer(pname, dwSize);
  std::wcout << "Default printer is" << default_printer << std::endl;

  // EnumPrintersW(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 5, NULL, 0, &dwNeeded, &dwReturned);

  pinfo = (PRINTER_INFO_5W*)malloc(dwNeeded);

  EnumPrintersW(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 5, (PBYTE)pinfo, dwNeeded, &dwNeeded, &dwReturned);

  return 0;
}
