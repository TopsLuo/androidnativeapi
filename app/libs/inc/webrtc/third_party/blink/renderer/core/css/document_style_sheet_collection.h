/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 *           (C) 2006 Alexey Proskuryakov (ap@webkit.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2012 Apple Inc. All
 * rights reserved.
 * Copyright (C) 2008, 2009 Torch Mobile Inc. All rights reserved.
 * (http://www.torchmobile.com/)
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies)
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_DOCUMENT_STYLE_SHEET_COLLECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_DOCUMENT_STYLE_SHEET_COLLECTION_H_

#include "base/macros.h"
#include "third_party/blink/renderer/core/css/tree_scope_style_sheet_collection.h"

namespace blink {

class DocumentStyleSheetCollector;
class StyleEngine;
class TreeScope;
class ViewportStyleResolver;

class DocumentStyleSheetCollection final
    : public TreeScopeStyleSheetCollection {
 public:
  static DocumentStyleSheetCollection* Create(TreeScope& tree_scope) {
    return new DocumentStyleSheetCollection(tree_scope);
  }

  void UpdateActiveStyleSheets(StyleEngine& master_engine);
  void CollectStyleSheets(StyleEngine& master_engine,
                          DocumentStyleSheetCollector&);
  void CollectViewportRules(ViewportStyleResolver&);

  void Trace(blink::Visitor* visitor) override {
    TreeScopeStyleSheetCollection::Trace(visitor);
  }

 private:
  explicit DocumentStyleSheetCollection(TreeScope&);

  void CollectStyleSheetsFromCandidates(StyleEngine& master_engine,
                                        DocumentStyleSheetCollector&);
  DISALLOW_COPY_AND_ASSIGN(DocumentStyleSheetCollection);
};

}  // namespace blink

#endif
