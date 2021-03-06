/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSMessagePort.h"

#include "Event.h"
#include "EventListener.h"
#include "Frame.h"
#include "JSDOMGlobalObject.h"
#include "JSEvent.h"
#include "JSEventListener.h"
#include "MessagePort.h"
#include "PlatformString.h"
#include "RegisteredEventListener.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSMessagePort);

/* Hash table */

static const HashTableValue JSMessagePortTableValues[3] =
{
    { "onmessage", DontDelete, (intptr_t)jsMessagePortOnmessage, (intptr_t)setJSMessagePortOnmessage },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsMessagePortConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSMessagePortTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSMessagePortTableValues, 0 };
#else
    { 4, 3, JSMessagePortTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSMessagePortConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSMessagePortConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSMessagePortConstructorTableValues, 0 };
#else
    { 1, 0, JSMessagePortConstructorTableValues, 0 };
#endif

class JSMessagePortConstructor : public DOMConstructorObject {
public:
    JSMessagePortConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSMessagePortConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSMessagePortPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSMessagePortConstructor::s_info = { "MessagePortConstructor", 0, &JSMessagePortConstructorTable, 0 };

bool JSMessagePortConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSMessagePortConstructor, DOMObject>(exec, &JSMessagePortConstructorTable, this, propertyName, slot);
}

bool JSMessagePortConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSMessagePortConstructor, DOMObject>(exec, &JSMessagePortConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSMessagePortPrototypeTableValues[7] =
{
    { "postMessage", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionPostMessage, (intptr_t)2 },
    { "start", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionStart, (intptr_t)0 },
    { "close", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionClose, (intptr_t)0 },
    { "addEventListener", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionAddEventListener, (intptr_t)3 },
    { "removeEventListener", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionRemoveEventListener, (intptr_t)3 },
    { "dispatchEvent", DontDelete|Function, (intptr_t)jsMessagePortPrototypeFunctionDispatchEvent, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSMessagePortPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 31, JSMessagePortPrototypeTableValues, 0 };
#else
    { 17, 15, JSMessagePortPrototypeTableValues, 0 };
#endif

static const HashTable* getJSMessagePortPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSMessagePortPrototypeTable);
}
const ClassInfo JSMessagePortPrototype::s_info = { "MessagePortPrototype", 0, 0, getJSMessagePortPrototypeTable };

JSObject* JSMessagePortPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSMessagePort>(exec, globalObject);
}

bool JSMessagePortPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, getJSMessagePortPrototypeTable(exec), this, propertyName, slot);
}

bool JSMessagePortPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, getJSMessagePortPrototypeTable(exec), this, propertyName, descriptor);
}

static const HashTable* getJSMessagePortTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSMessagePortTable);
}
const ClassInfo JSMessagePort::s_info = { "MessagePort", 0, 0, getJSMessagePortTable };

JSMessagePort::JSMessagePort(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<MessagePort> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSMessagePort::~JSMessagePort()
{
    impl()->invalidateEventListeners();
    forgetDOMObject(this, impl());
}

JSObject* JSMessagePort::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSMessagePortPrototype(JSMessagePortPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSMessagePort::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSMessagePort, Base>(exec, getJSMessagePortTable(exec), this, propertyName, slot);
}

bool JSMessagePort::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSMessagePort, Base>(exec, getJSMessagePortTable(exec), this, propertyName, descriptor);
}

JSValue jsMessagePortOnmessage(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSMessagePort* castedThis = static_cast<JSMessagePort*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    MessagePort* imp = static_cast<MessagePort*>(castedThis->impl());
    if (EventListener* listener = imp->onmessage()) {
        if (JSObject* jsFunction = listener->jsFunction(imp->scriptExecutionContext()))
            return jsFunction;
    }
    return jsNull();
}

JSValue jsMessagePortConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSMessagePort* domObject = static_cast<JSMessagePort*>(asObject(slot.slotBase()));
    return JSMessagePort::getConstructor(exec, domObject->globalObject());
}
void JSMessagePort::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSMessagePort, Base>(exec, propertyName, value, getJSMessagePortTable(exec), this, slot);
}

void setJSMessagePortOnmessage(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    MessagePort* imp = static_cast<MessagePort*>(static_cast<JSMessagePort*>(thisObject)->impl());
    JSDOMGlobalObject* globalObject = toJSDOMGlobalObject(imp->scriptExecutionContext(), exec);
    if (!globalObject)
        return;
    imp->setOnmessage(globalObject->createJSAttributeEventListener(value));
}

JSValue JSMessagePort::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSMessagePortConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionPostMessage(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    return castedThisObj->postMessage(exec, args);
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionStart(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    MessagePort* imp = static_cast<MessagePort*>(castedThisObj->impl());

    imp->start();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionClose(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    MessagePort* imp = static_cast<MessagePort*>(castedThisObj->impl());

    imp->close();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionAddEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    return castedThisObj->addEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionRemoveEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    return castedThisObj->removeEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsMessagePortPrototypeFunctionDispatchEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSMessagePort::s_info))
        return throwError(exec, TypeError);
    JSMessagePort* castedThisObj = static_cast<JSMessagePort*>(asObject(thisValue));
    MessagePort* imp = static_cast<MessagePort*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Event* evt = toEvent(args.at(0));


    JSC::JSValue result = jsBoolean(imp->dispatchEvent(evt, ec));
    setDOMException(exec, ec);
    return result;
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, MessagePort* object)
{
    return getDOMObjectWrapper<JSMessagePort>(exec, globalObject, object);
}
MessagePort* toMessagePort(JSC::JSValue value)
{
    return value.inherits(&JSMessagePort::s_info) ? static_cast<JSMessagePort*>(asObject(value))->impl() : 0;
}

}
