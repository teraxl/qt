/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

import Qt 4.7

Rectangle {
    width: 600; height: 300

    // Show the model in three lists, with different highlight ranges.
    // preferredHighlightBegin and preferredHighlightEnd set the
    // range in which to attempt to maintain the highlight.
    //
    // The second and third ListView set their currentIndex to be the
    // same as the first, and the first ListView is given keyboard focus.
    //
    // The first list does not set a highlight range, so its currentItem
    // can move freely within the visible area. If it moves outside the
    // visible area, the view is automatically scrolled to keep the current
    // item visible.
    //
    // The second list sets a highlight range which attempts to keep the
    // current item within the the bounds of the range. However,
    // items will not scroll beyond the beginning or end of the view,
    // forcing the highlight to move outside the range at the ends.
    //
    // The third list sets the highlightRangeMode to StrictlyEnforceRange
    // and sets a range smaller than the height of an item.  This
    // forces the current item to change when the view is flicked,
    // since the highlight is unable to move.
    //
    // Note that the first ListView sets its currentIndex to be equal to
    // the third ListView's currentIndex.  By flicking List3 with
    // the mouse, the current index of List1 will be changed.

    ListView {
        id: list1
        width: 200; height: parent.height
        model: PetsModel {}
        delegate: petDelegate

        highlight: Rectangle { color: "lightsteelblue" }
        currentIndex: list3.currentIndex
        focus: true
    }

    ListView {
        id: list2
        x: list1.width
        width: 200; height: parent.height
        model: PetsModel {}
        delegate: petDelegate

        highlight: Rectangle { color: "yellow" }
        currentIndex: list1.currentIndex
        preferredHighlightBegin: 80; preferredHighlightEnd: 220
        highlightRangeMode: ListView.ApplyRange
    }

    ListView {
        id: list3
        x: list1.width + list2.width
        width: 200; height: parent.height
        model: PetsModel {}
        delegate: petDelegate

        highlight: Rectangle { color: "yellow" }
        currentIndex: list1.currentIndex
        preferredHighlightBegin: 125; preferredHighlightEnd: 125
        highlightRangeMode: ListView.StrictlyEnforceRange
    }

    // The delegate for each list
    Component {
        id: petDelegate
        Column {
            width: 200
            Text { text: 'Name: ' + name }
            Text { text: 'Type: ' + type }
            Text { text: 'Age: ' + age }
        }
    }
}