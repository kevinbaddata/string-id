#pragma once

namespace SID
{
	class DB
	{
	public:
		DB();
		~DB();
		static void saveHash();
		static void loadHash();
		static void cleanHash();
		
	};
	
}

			