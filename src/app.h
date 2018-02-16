// 
// app.h : Define macros and include files for CQ app.
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

#pragma once

#define CQAPP_ID "top.jogle.ctbx"
#define CQAPP_NAME "CoolQ Telegram Bot X"
#define CQAPP_VERSION "10.0.0"
#define CQAPP_BUILD_NUMBER 1
#define CQAPP_FULLNAME CQAPP_NAME " v" CQAPP_VERSION
#define CQAPP_USER_AGENT "CTBX/" CQAPP_VERSION

#include "common.h"

#include "application_class.h"
extern Application app;

#include "cqp/sdk.h"
extern std::optional<Sdk> sdk;

#include "conf/config_struct.h"
extern Config config;

#include "ctpl/ctpl_stl.h"
extern std::shared_ptr<ctpl::thread_pool> pool;

#include "log_class.h"

#include "tgbot\tgbot.h"
extern std::shared_ptr<TgBot::Bot> tgbot;
extern int32_t forward_enable;