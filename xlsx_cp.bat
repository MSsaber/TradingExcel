@echo off
setlocal

:: QXlsx
set QXlsxFolder=.\QXlsx\
set QXlsxExcelLib="%QXlsxFolder%"\lib\
set QXlsxExcelHeader="%QXlsxFolder%"\incldue\
set QXlsxExcelRelease="%QXlsxFolder%"\lib\release\
set QXlsxExcelDebug="%QXlsxFolder%"\lib\debug\

:: 检查目标文件夹是否存在，如果不存在则创建它
if not exist "%QXlsxFolder%" (
    echo Target folder does not exist. Creating...
    mkdir "%QXlsxFolder%"
    if %errorlevel% neq 0 (
        echo Failed to create target folder.
        goto End
    )
)

if not exist "%QXlsxExcelLib%" (
    echo Target folder does not exist. Creating...
    mkdir "%QXlsxExcelLib%"
    if %errorlevel% neq 0 (
        echo Failed to create target folder.
        goto End
    )
)

if not exist "%QXlsxExcelHeader%" (
    echo Target folder does not exist. Creating...
    mkdir "%QXlsxExcelHeader%"
    if %errorlevel% neq 0 (
        echo Failed to create target folder.
        goto End
    )
)

if exist "%QXlsxExcelDebug%" (
    echo debug deleting...
    rd /s "%QXlsxExcelDebug%"
    if %errorlevel% equ 0 (
        echo debug delete successfully.
    ) else (
        echo Failed to delete debug
    )
)

if exist "%QXlsxExcelRelease%" (
    echo release deleting...
    rd /s "%QXlsxExcelRelease%"
    if %errorlevel% equ 0 (
        echo release delete successfully.
    ) else (
        echo Failed to delete release
    )
)

xcopy "..\QXlsx\QXlsx\header\*.h" "%QXlsxExcelHeader%\" /I /Y
set QXlsExcelBuild="..\QXlsx\QXlsx\build\"

echo Copying .a and .dll files to target folder...
:: 遍历根目录下的所有文件夹
for /d %%D in ("%QXlsExcelBuild%*") do (
    :: 注意：这里"%%QXlsExcelBuild%*"其实是不必要的，因为/d只处理文件夹
    :: 直接用"%%D"遍历即可，但我们需要检查文件夹名
    set "folderName=%%~nxD"
    :: 检查文件夹名称中是否包含"Debug"
    if "!folderName:Debug=!" neq "!folderName!" (
        echo Found Debug folder: %%D
        :: 拷贝所有的.lib文件到目标文件夹
        xcopy "%%D\debug\*.dll" "%QXlsxExcelDebug%\" /I /Y
        xcopy "%%D\debug\*.a" "%QXlsxExcelDebug%\" /I /Y
        xcopy "%%D\debug\*.lib" "%QXlsxExcelDebug%\" /I /Y
    )
)

endlocal