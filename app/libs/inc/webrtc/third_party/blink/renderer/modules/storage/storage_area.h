/*
 * Copyright (C) 2008 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_AREA_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_AREA_H_

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/core/dom/context_lifecycle_observer.h"
#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/forward.h"

namespace blink {

class ExceptionState;
class LocalFrame;
class WebStorageArea;
class WebStorageNamespace;

class StorageArea final : public ScriptWrappable, public ContextClient {
  DEFINE_WRAPPERTYPEINFO();
  USING_GARBAGE_COLLECTED_MIXIN(StorageArea);

 public:
  enum class StorageType { kLocalStorage, kSessionStorage };

  static StorageArea* Create(LocalFrame*,
                             std::unique_ptr<WebStorageArea>,
                             StorageType);

  unsigned length(ExceptionState&) const;
  String key(unsigned index, ExceptionState&) const;
  String getItem(const String& key, ExceptionState&) const;
  bool setItem(const String& key, const String& value, ExceptionState&);
  DeleteResult removeItem(const String& key, ExceptionState&);
  void clear(ExceptionState&);
  bool Contains(const String& key, ExceptionState& ec) const;

  WebStorageArea* Area() const { return storage_area_.get(); }

  void NamedPropertyEnumerator(Vector<String>&, ExceptionState&);
  bool NamedPropertyQuery(const AtomicString&, ExceptionState&);

  bool CanAccessStorage() const;

  void Trace(blink::Visitor*) override;

  static void DispatchLocalStorageEvent(const String& key,
                                        const String& old_value,
                                        const String& new_value,
                                        const SecurityOrigin*,
                                        const KURL& page_url,
                                        WebStorageArea* source_area_instance);
  static void DispatchSessionStorageEvent(const String& key,
                                          const String& old_value,
                                          const String& new_value,
                                          const SecurityOrigin*,
                                          const KURL& page_url,
                                          const WebStorageNamespace&,
                                          WebStorageArea* source_area_instance);

 private:
  StorageArea(LocalFrame*, std::unique_ptr<WebStorageArea>, StorageType);

  std::unique_ptr<WebStorageArea> storage_area_;
  StorageType storage_type_;

  mutable bool did_check_can_access_storage_ = false;
  mutable bool can_access_storage_cached_result_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_AREA_H_
