#include <vector>
#include <algorithm>


struct keyError : std::exception
{
	virtual const char *what() throw()
	{
		return "key error";
	}
};
struct valueError : std::exception
{
	virtual const char *what() throw()
	{
		return "value error";
	}
};
template <typename T, typename S>
class HashMap
{
	std::vector<T> _key_array;
	std::vector<S> _value_array;

	int getKeyIndex(const T &_key)
	{
		auto indx = std::find(this->_key_array.begin(), this->_key_array.end(), _key);
		auto _index = (indx != this->_key_array.end()) ? std::distance(this->_key_array.begin(), indx) : -1;
		return _index;
	}
	int getValueIndex(const S &_value)
	{
		auto indx = std::find(this->_value_array.begin(), this->_value_array.end(), _value);
		auto _index = (indx != this->_value_array.end()) ? std::distance(this->_value_array.begin(), indx) : -1;
		return _index;
	}

  public:
	void setValue(const T &_key, const S &_value)
	{
		int index = this->getKeyIndex(_key);
		if(index != -1)
		{
			this->_key_array[index] = _key;
			this->_value_array[index] = _value;
		}
		else
		{
			this->_key_array.push_back(_key);
			this->_value_array.push_back(_value);
		}
	}
	S getValue(const T &_key)
	{
		int index = this->getKeyIndex(_key);
		if (index != -1)
		{
			return this->_value_array[index];
		}
		else
		{
			throw keyError();
		}
	}
	T getKey(const S &_value)
	{
		int index = this->getValueIndex(_value);
		if (index != -1)
		{
			return this->_key_array[index];
		}
		else
		{
			throw valueError();
		}
	}
	int size()
	{
		return this->_key_array.size();
	}
};
