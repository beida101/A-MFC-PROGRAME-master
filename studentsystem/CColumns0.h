// CColumns0.h : �� Microsoft Visual C++ ������ ActiveX �ؼ���װ�������

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CColumns0

class CColumns0 : public COleDispatchDriver
{
public:
	CColumns0() {}		// ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CColumns0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CColumns0(const CColumns0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// ����
public:

// ����
public:

	long get_Count()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN _NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Add(short Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	LPDISPATCH get_Item(VARIANT Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	void Remove(VARIANT Index)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Index);
	}


};
