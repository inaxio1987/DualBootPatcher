/*
 * Copyright (C) 2017  Andrew Gunnerson <andrewgunnerson@gmail.com>
 *
 * This file is part of DualBootPatcher
 *
 * DualBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DualBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DualBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gmock/gmock.h>

#ifdef _WIN32
#  include <windows.h>
#endif

#include "mbcommon/error_code.h"

using namespace mb;

#ifdef _WIN32

TEST(ErrorCodeTest, Win32CheckRoundTrip)
{
    auto ec = std::error_code(ERROR_FILE_NOT_FOUND, win32_error_category());
    ASSERT_TRUE(ec);
    ASSERT_EQ(ec.value(), ERROR_FILE_NOT_FOUND);
}

TEST(ErrorCodeTest, Win32CheckErrorMessage)
{
    auto ec = std::error_code(ERROR_FILE_NOT_FOUND, win32_error_category());
    ASSERT_TRUE(ec);
    ASSERT_EQ(ec.message(), "File not found");
}

TEST(ErrorCodeTest, Win32ComparableToStdErrc)
{
    auto ec = std::error_code(ERROR_FILE_NOT_FOUND, win32_error_category());
    ASSERT_TRUE(ec);
    ASSERT_EQ(ec, std::errc::no_such_file_or_directory);
}

#endif
