// 
// menuentry.cpp : Export menu entry functions to DLL.
// 
// Copyright (C) 2017  Richard Chien <richardchienthebest@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 

#include "app.h"

#include "update.h"
#include "api/api.h"

using namespace std;

/**
 * Menu: Show config.
 */
CQEVENT(int32_t, __menu_restart, 0)() {
	string s = "notepad.exe " + sdk->directories().app() + "config.cfg";
	WinExec(s.c_str(), SW_SHOW);
	return 0;
}

/**
 * Menu: About Coolq Telegram Bot X
 */
CQEVENT(int32_t, __menu_check_update, 0)() {
	MessageBoxA(NULL, "Coolq Telegram Bot X \r\nhttps://github.com/JogleLew/coolq-telegram-bot-x", "", 0);
    return 0;
}

/**
 * Menu: Restart CoolQ.
 */
CQEVENT(int32_t, __menu_restart_coolq, 0)() {
    invoke_api("set_restart");
    return 0;
}
