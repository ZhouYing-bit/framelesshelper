/*
 * MIT License
 *
 * Copyright (C) 2021 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "framelesshelper_global.h"
#include <QtGui/qwindow.h>

FRAMELESSHELPER_BEGIN_NAMESPACE

enum class SystemMetric
{
    ResizeBorderWidth,
    ResizeBorderHeight,
    TitleBarHeight
};

namespace Utilities
{

[[nodiscard]] FRAMELESSHELPER_API int getSystemMetric(const QWindow *window, const SystemMetric metric, const bool dpiScale, const bool forceSystemValue = false);
[[nodiscard]] FRAMELESSHELPER_API QWindow *findWindow(const WId winId);
[[nodiscard]] FRAMELESSHELPER_API bool shouldUseNativeTitleBar();
[[nodiscard]] FRAMELESSHELPER_API bool isWindowFixedSize(const QWindow *window);
[[nodiscard]] FRAMELESSHELPER_API QPointF getGlobalMousePosition(const QWindow *window);
[[nodiscard]] FRAMELESSHELPER_API bool isHitTestVisibleInChrome(const QWindow *window);
[[nodiscard]] FRAMELESSHELPER_API QPointF mapOriginPointToWindow(const QObject *object);

#ifdef Q_OS_WINDOWS
[[nodiscard]] FRAMELESSHELPER_API bool isWin8OrGreater();
[[nodiscard]] FRAMELESSHELPER_API bool isWin8Point1OrGreater();
[[nodiscard]] FRAMELESSHELPER_API bool isWin10OrGreater();
[[nodiscard]] FRAMELESSHELPER_API bool isDwmCompositionAvailable();
FRAMELESSHELPER_API void triggerFrameChange(const WId winId);
FRAMELESSHELPER_API void updateFrameMargins(const WId winId, const bool reset);
FRAMELESSHELPER_API void updateQtFrameMargins(QWindow *window, const bool enable);
#endif

}

FRAMELESSHELPER_END_NAMESPACE
