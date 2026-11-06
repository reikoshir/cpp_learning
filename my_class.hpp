#include <string>
#include <functional>

class MyKeyClass
{
public:
	MyKeyClass(int i, std::string name, bool flag)
		: m_i(i), m_name(name), m_flag(flag)
	{

	}

	bool operator==(const MyKeyClass& other) const
	{
		return m_i == other.m_i &&
			m_name == other.m_name &&
			m_flag == other.m_flag;
	}

	bool operator!=(const MyKeyClass& other) const
	{
		return !(*this == other);
	}

	bool operator<(const MyKeyClass& other) const
	{
		if (m_i != other.m_i)
		{
			return m_i < other.m_i;
		} 
		else if (m_name != other.m_name)
		{
			return m_name < other.m_name;
		}
		else
		{
			return m_flag < other.m_flag;
		}
	}

	int get_i() const
	{
		return m_i;
	}

	std::string get_name() const
	{
		return m_name;
	}

	bool get_flag() const
	{
		return m_flag;
	}

private:
	int m_i;
	std::string m_name;
	bool m_flag;
};

namespace std
{
	template<>
	struct hash<MyKeyClass>
	{
		size_t operator()(const MyKeyClass& obj) const
		{
			size_t h1 = hash<int>{}(obj.get_i());
			size_t h2 = hash<string>{}(obj.get_name());
			size_t h3 = hash<bool>{}(obj.get_flag());

			return h1 ^ (h2 << 1) ^ (h3 << 2);
		}
	};
}