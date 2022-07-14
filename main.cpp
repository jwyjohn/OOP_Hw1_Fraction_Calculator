/*****************************************************************//**
 * \file   main.cpp
 * \brief  Do testing.
 *
 * \author jwy
 * \date   July 2022
 *********************************************************************/
#include<iostream>
#include<string>
#include<map>
#include"fraction.h"
#include"mynat.h"

using namespace std;

void show_banner()
{
	cout << "    ____                __  _           " << endl;
	cout << "   / __/________ ______/ /_(_)___  ____ " << endl;
	cout << "  / /_/ ___/ __ `/ ___/ __/ / __ \\/ __ \\" << endl;
	cout << " / __/ /  / /_/ / /__/ /_/ / /_/ / / / /" << endl;
	cout << "/_/ /_/   \\__,_/\\___/\\__/_/\\____/_/ /_/ " << endl;
	cout << endl;
	cout << "Fraction test, type 'help' for more help." << endl;
}

void show_help();

int main()
{
	//cout << (myint(4) % myint(2)).to_string() << endl;
	//return 0;
	show_banner();
	string op;
	map<string, fraction> workspace;
	while (true)
	{
		cout << "\nfraction> ";
		cin >> op;
		if (op == "#")
		{
			cin.ignore(32768, '\n');
		}
		if (op == "help")
		{
			show_help();
		}
		if (op == "init")
		{
			workspace.clear();
			cout << "[DONE] Workspace reset." << endl;
		}
		if (op == "list")
		{
			cout << "[VARIABLES]" << endl;
			for (auto& it : workspace) {
				cout << it.first << " = " << it.second.to_string() << endl;
			}
		}
		if (op == "show")
		{
			string name;
			cin >> name;
			if (1 == workspace.count(name))
			{
				cout << name << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "lf")
		{
			string name;
			double f;
			cin >> name >> f;
			workspace[name] = fraction(f);
			if (1 == workspace.count(name))
			{
				cout << name << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "li")
		{
			string name, f;
			cin >> name >> f;
			workspace[name] = fraction(f);
			if (1 == workspace.count(name))
			{
				cout << name << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "reduce")
		{
			string name;
			cin >> name;
			if (1 == workspace.count(name))
			{
				cout << name << " = " << workspace[name].to_string();
				workspace[name] = workspace[name].reduce();
				cout << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "neg")
		{
			string name;
			cin >> name;
			if (1 == workspace.count(name))
			{
				workspace[name] = -workspace[name];
				cout << name << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "inv")
		{
			string name;
			cin >> name;
			if (1 == workspace.count(name))
			{
				workspace[name] = workspace[name].reciprocal();
				cout << name << " = " << workspace[name].to_string() << endl;
			}
			else
			{
				clog << "[Error] fraction " << name << " not exist" << endl;
			}
		}
		if (op == "add")
		{
			string t, s1, s2;
			cin >> t >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			workspace[t] = workspace[s1] + workspace[s2];
			cout << t << " = ";
			workspace[t].display();
		}
		if (op == "sub")
		{
			string t, s1, s2;
			cin >> t >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			workspace[t] = workspace[s1] - workspace[s2];
			cout << t << " = ";
			workspace[t].display();
		}
		if (op == "mul")
		{
			string t, s1, s2;
			cin >> t >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			workspace[t] = workspace[s1] * workspace[s2];
			cout << t << " = ";
			workspace[t].display();
		}
		if (op == "div")
		{
			string t, s1, s2;
			cin >> t >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			workspace[t] = workspace[s1] / workspace[s2];
			cout << t << " = ";
			workspace[t].display();
		}
		if (op == "eq")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] == workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
		if (op == "gt")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] > workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
		if (op == "lt")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] < workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
		if (op == "geq")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] >= workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
		if (op == "leq")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] <= workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
		if (op == "neq")
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (1 != workspace.count(s1))
			{
				clog << "[Error] fraction " << s1 << " not exist" << endl;
				continue;
			}
			if (1 != workspace.count(s2))
			{
				clog << "[Error] fraction " << s2 << " not exist" << endl;
				continue;
			}
			cout << s1 << " = ";
			workspace[s1].display();
			cout << s2 << " = ";
			workspace[s2].display();
			if (workspace[s1] != workspace[s2])
			{
				cout << "#True" << endl;
			}
			else
			{
				cout << "#False" << endl;
			}
		}
	}
	return 0;
}

void show_help()
{
	cout << "[HELP]" << endl;
	cout << "                    # [comment]: comment, do nothing" << endl;
	cout << "                          help : show this message" << endl;
	cout << "                          init : clear workspace" << endl;
	cout << "       li [var_name:str] [a/b] : assign var_name <- a/b" << endl;
	cout << " lf [var_name:str] [f: double] : assign var_name <- f" << endl;
	cout << "           show [var_name:str] : show var_name" << endl;
	cout << "                         list  : show all variables in workspae" << endl;
	cout << "              reduce [var:str] : reduce var to normal form" << endl;
	cout << "                 neg [var:str] : var <- -(var)" << endl;
	cout << "                 inv [var:str] : var <- 1/var" << endl;
	cout << " add [t:str] [s1:str] [s2:str] : t <- s1 + s2" << endl;
	cout << " sub [t:str] [s1:str] [s2:str] : t <- s1 - s2" << endl;
	cout << " mul [t:str] [s1:str] [s2:str] : t <- s1 * s2" << endl;
	cout << " div [t:str] [s1:str] [s2:str] : t <- s1 * s2" << endl;
	cout << "          eq [s1:str] [s2:str] : s1 == s2 ? " << endl;
	cout << "          gt [s1:str] [s2:str] : s1 > s2 ? " << endl;
	cout << "          lt [s1:str] [s2:str] : s1 lt s2 ? " << endl;
	cout << "         geq [s1:str] [s2:str] : s1 >= s2 ? " << endl;
	cout << "         leq [s1:str] [s2:str] : s1 <= s2 ? " << endl;
	cout << "         neq [s1:str] [s2:str] : s1 != s2 ? " << endl;
}
