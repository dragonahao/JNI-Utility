#ifndef FR_PLANQUART_JNI_METHOD_HPP
#define FR_PLANQUART_JNI_METHOD_HPP

#include <jni.h>

#include "Signature.hpp"

namespace fr
{
namespace Planquart
{
namespace JNI
{
	class Class;
	class Object;

	class Method
	{
	public:
		friend class Class;
		friend class Object;

		bool isStatic()
		{
			return this->_static;
		}

	private:
		Method(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic = false);

		Class* classObject;
		Signature* signature;
		jmethodID methodID;
		bool _static;
	};
}
}
}

#endif /* FR_PLANQUART_JNI_METHOD_HPP */

