//
// SocketAddressImpl.cpp
//
// $Id: //poco/1.4/Net/src/SocketAddressImpl.cpp#5 $
//
// Library: Net
// Package: NetCore
// Module:  SocketAddressImpl
//
// Copyright (c) 2005-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/Net/SocketAddressImpl.h"
#include "Poco/Net/SocketDefs.h"
#include <cstring>


namespace Poco {
namespace Net {
namespace Impl {

//
// SocketAddressImpl
//


SocketAddressImpl::SocketAddressImpl()
{
}


SocketAddressImpl::~SocketAddressImpl()
{
}


//
// IPv4SocketAddressImpl
//


IPv4SocketAddressImpl::IPv4SocketAddressImpl()
{
	std::memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	poco_set_sin_len(&_addr);
}


IPv4SocketAddressImpl::IPv4SocketAddressImpl(const struct sockaddr_in* addr)
{
	std::memcpy(&_addr, addr, sizeof(_addr));
}


IPv4SocketAddressImpl::IPv4SocketAddressImpl(const void* addr, UInt16 port)
{
	std::memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	std::memcpy(&_addr.sin_addr, addr, sizeof(_addr.sin_addr));
	_addr.sin_port = port;
}


#if defined(POCO_HAVE_IPv6)


//
// IPv6SocketAddressImpl
//


IPv6SocketAddressImpl::IPv6SocketAddressImpl(const struct sockaddr_in6* addr)
{
	std::memcpy(&_addr, addr, sizeof(_addr));
}


IPv6SocketAddressImpl::IPv6SocketAddressImpl(const void* addr, UInt16 port)
{
	std::memset(&_addr, 0, sizeof(_addr));
	_addr.sin6_family = AF_INET6;
	poco_set_sin6_len(&_addr);
	std::memcpy(&_addr.sin6_addr, addr, sizeof(_addr.sin6_addr));
	_addr.sin6_port = port;
}


IPv6SocketAddressImpl::IPv6SocketAddressImpl(const void* addr, UInt16 port, UInt32 scope)
{
	std::memset(&_addr, 0, sizeof(_addr));
	_addr.sin6_family = AF_INET6;
	poco_set_sin6_len(&_addr);
	std::memcpy(&_addr.sin6_addr, addr, sizeof(_addr.sin6_addr));
	_addr.sin6_port = port;
	_addr.sin6_scope_id = scope;
}


#endif // POCO_HAVE_IPv6


} } } // namespace Poco::Net::Impl
