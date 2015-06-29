rem -------------------------------------------------------------------------
rem create-windows.sh
rem
rem Create a Windows directory for the installer to use.
rem
rem Copyright 2006-2012 Boshvark Software, LLC.
rem
rem This file is part of Zyzzyva.
rem
rem Zyzzyva is free software; you can redistribute it and/or modify
rem it under the terms of the GNU General Public License as published by
rem the Free Software Foundation; either version 2 of the License, or
rem (at your option) any later version.
rem
rem Zyzzyva is distributed in the hope that it will be useful,
rem but WITHOUT ANY WARRANTY; without even the implied warranty of
rem MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
rem GNU General Public License for more details.
rem
rem You should have received a copy of the GNU General Public License
rem along with this program; if not, write to the Free Software
rem Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
rem -------------------------------------------------------------------------

setlocal

set QTVER=5.4\mingw491_32
set QTDIR=E:\Qt\%QTVER%
set INSTDIR=installer
set PLATFORM=windows
set OUTDIR=%INSTDIR%\%PLATFORM%

qmake
CALL mingw32-make

mkdir %OUTDIR%

rem Copy Qt libraries
copy %QTDIR%\bin\assistant.exe %OUTDIR%
copy %QTDIR%\bin\QtAssistantClient4.dll %OUTDIR%
copy %QTDIR%\bin\QtCore4.dll %OUTDIR%
copy %QTDIR%\bin\QtGui4.dll %OUTDIR%
copy %QTDIR%\bin\QtNetwork4.dll %OUTDIR%
copy %QTDIR%\bin\QtSql4.dll %OUTDIR%
copy %QTDIR%\bin\QtXml4.dll %OUTDIR%
rem copy %QTDIR%\bin\mingwm10.dll %OUTDIR%
rem copy %QTDIR%\bin\assistant.exe %OUTDIR%
rem copy %QTDIR%\bin\QtAssistantClient4.dll %OUTDIR%
rem copy %QTDIR%\bin\Qt5Core.dll %OUTDIR%
rem copy %QTDIR%\bin\Qt5Gui.dll %OUTDIR%
rem copy %QTDIR%\bin\Qt5Network.dll %OUTDIR%
rem copy %QTDIR%\bin\Qt5Sql.dll %OUTDIR%
remcopy %QTDIR%\bin\Qt5Xml.dll %OUTDIR%
rem copy %QTDIR%\bin\mingwm10.dll %OUTDIR%

rem Copy Qt plugins
mkdir %OUTDIR%\sqldrivers
rem copy %QTDIR%\plugins\sqldrivers\qsqlite4.dll %OUTDIR%\sqldrivers
copy E:\Qt\%QTDIR%\plugins\sqldrivers\qsqlit4.dll %OUTDIR%\sqldrivers

rem Copy Zyzzyva images
mkdir %OUTDIR%\images
copy images\Zyzzyva.ico %OUTDIR%\images

rem Copy Zyzzyva stuff
copy bin\zyzzyva.exe %OUTDIR%
copy bin\zyzzyva2.dll %OUTDIR%
copy zyzzyva.top %OUTDIR%
copy AUTHORS %OUTDIR%\AUTHORS.txt
copy CHANGES %OUTDIR%\CHANGES.txt
copy COPYING %OUTDIR%\COPYING.txt
copy LICENSE %OUTDIR%\LICENSE.txt
copy README %OUTDIR%\README.txt

rem Copy Zyzzyva data directory
xcopy /I /E /H data %OUTDIR%\data

endlocal
