#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

template <class T>
class Ref {
public:
	typedef T _TpBase;
	typedef std::shared_ptr<T> _TpPtr;

private:
	Ref(const _TpPtr& o);

	_TpPtr _object;

public:
	Ref();

	Ref(std::nullptr_t);

	template <class U, typename std::enable_if<
		std::is_base_of<T, U>::value, U>::type* = nullptr>
	Ref(const Ref<U>& ref);

	template <class U, typename std::enable_if<
		!std::is_base_of<T, U>::value, U>::type* = nullptr>
	explicit Ref(const Ref<U>& ref);
	
	template <class... Args>
	static Ref<T> New(Args&&... args);

	Ref<T>& operator =(const Ref<T>& rhs);

	T* operator ->() const;

	bool operator !() const;

	bool operator ==(const Ref<T>& rhs) const;

	bool operator !=(const Ref<T>& rhs) const;

	T* data() const;

	/* Constructs a reference from an allocated pointer
	 * WARNING: risk of dangling pointer
	 * You should not use this function
	 * unless you know what you are doing
	 */
	static Ref FromPtr(T*);

	friend T;
	template <class U>
	friend class Ref;
	template <class U>
	friend class Ref_w;
};

CB_END_NAMESPACE

#include "detail/ptrref.inl"