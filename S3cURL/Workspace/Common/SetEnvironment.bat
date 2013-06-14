
@echo off

:: Setup SolidMCP Environment
goto SETENVIRONMENTS
goto SETCOMPONENTS

goto STARTDEVIDE
goto THEEND

:SETENVIRONMENTS

set SMCP_ROOT=s:

set SMCP_COMPONENTS=%SMCP_ROOT%\Components
set SMCP_COMPONENTS_CPP=%SMCP_COMPONENTS%\CPlusPlus

:SETCOMPONENTS
set SMCP_COMP_CPP_CURL=%SMCP_COMPONENTS_CPP%\cURL\curl-7.20.0
set SMCP_COMP_CPP_OPENSSL=%SMCP_COMPONENTS_CPP%\OpenSSL\OpenSSL-0.9.8m

:: Set Debug dll pathes
set PATH=%PATH%;%SMCP_COMP_CPP_CURL%\lib\DLL-Debug
set PATH=%PATH%;%SMCP_COMP_CPP_OPENSSL%\out32dll

:: Set Release dll pathes
set PATH=%PATH%;%SMCP_COMP_CPP_CURL%\lib\DLL-Release
set PATH=%PATH%;%SMCP_COMP_CPP_OPENSSL%\out32dll



set SMCP_UNZIP_TOOL=%SMCP_ROOT%\Tools\unzip\unzip.exe

set TARGET_PATH=%SMCP_ROOT%\Components\CPlusPlus\cURL\curl-7.20.0
if not exist %TARGET_PATH% md %TARGET_PATH%
if not exist %TARGET_PATH%\Win32  %SMCP_UNZIP_TOOL%  %SMCP_ROOT%\Components\Packages\curl-7.20.0-win32.zip -d %TARGET_PATH%

set TARGET_PATH=%SMCP_ROOT%\Components\CPlusPlus\OpenSSL\OpenSSL-0.9.8m
if not exist %TARGET_PATH% md %TARGET_PATH%
if not exist %TARGET_PATH%\Win32  %SMCP_UNZIP_TOOL%  %SMCP_ROOT%\Components\Packages\OpenSSL-0.9.8m-win32.zip -d %TARGET_PATH%

:STARTDEVIDE
call %SMCP_ROOT%\Workspace\Develop\StartDevIDE.bat %1

:THEEND
set PATH
cd /d %SMCP_ROOT%

@echo on