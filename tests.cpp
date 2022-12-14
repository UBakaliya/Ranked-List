#include "barchartanimate.h"
#include <iostream>

using namespace std;

bool testBarDefaultConstructor()
{
	Bar b;
	if (b.getName() != "")
	{
		cout << "testBarDefaultConstructor: getName 'FAILED'" << endl;
		return false;
	}
	else if (b.getValue() != 0)
	{
		cout << "testBarDefaultConstructor: getValue 'FAILED'" << endl;
		return false;
	}
	else if (b.getCategory() != "")
	{
		cout << "testBarDefaultConstructor: getCategory 'FAILED'" << endl;
		return false;
	}
	cout << "testBarDefaultConstructor: all passed!" << endl;
	return true;
}

bool testBarParamConstructor()
{
	Bar b("Chicago", 9234324, "US");
	if (b.getName() != "Chicago")
	{
		cout << "testBarParamConstructor: getName 'FAILED'" << endl;
		return false;
	}
	else if (b.getValue() != 9234324)
	{
		cout << "testBarParamConstructor: getValue 'FAILED'" << endl;
		return false;
	}
	else if (b.getCategory() != "US")
	{
		cout << "testBarParamConstructor: getCategory 'FAILED'" << endl;
		return false;
	}
	cout << "testBarParamConstructor: all passed!" << endl;
	return true;
}

bool testBarOperators()
{
	bool objTest = true;

	Bar b1("UIC", 178915, "US");
	Bar b2("UIC", 188915, "US");
	objTest = b1 < b2; // less then
	if (objTest == 0)
	{
		cout << "testBarOperators: operator '<' 'FAILED'" << endl;
		return false;
	}

	Bar b3("UIC", 178911, "US");
	Bar b4("UIC", 178911, "US");
	objTest = b3 <= b4; // less then equal
	if (objTest == 0)
	{
		cout << "testBarOperators: operator '<=' 'FAILED'" << endl;
		return false;
	}

	Bar b5("UIC", 11278915, "US");
	Bar b6("UIC", 1127891, "US");
	objTest = b5 > b6; // less then equal
	if (objTest == 0)
	{
		cout << "testBarOperators: operator '>' 'FAILED'" << endl;
		return false;
	}

	Bar b7("UIC", 11278915, "US");
	Bar b8("UIC", 11278915, "US");
	objTest = b7 >= b8; // less then equal
	if (objTest == 0)
	{
		cout << "testBarOperators: operator '>=' 'FAILED'" << endl;
		return false;
	}

	cout << "testBarOperators: all passed!" << endl;
	return true;
}

bool testBarChartDefaultConstructor()
{
	BarChart b;
	if (b.getBars() != nullptr)
	{
		cout << "testBarChartDefaultConstructor: constructor getBars() 'FAILED'" << endl;
		return false;
	}
	else if (b.getCapacity() != 0)
	{
		cout << "testBarChartDefaultConstructor: constructor getCapacity() 'FAILED'" << endl;
		return false;
	}
	else if (b.getSize() != 0)
	{
		cout << "testBarChartDefaultConstructor: constructor getSize() 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartDefaultConstructor: all passed!" << endl;
	return true;
}

bool testBarChartParameterizedConstructor()
{
	BarChart b(10);
	if (b.getBars() == nullptr)
	{
		cout << "testBarCharParameterizedConstructor: Parameterized Constructor getBars() 'FAILED'" << endl;
		return false;
	}
	else if (b.getCapacity() != 10)
	{
		cout << "testBarCharParameterizedConstructor: Parameterized Constructor getCapacity() 'FAILED'" << endl;
		return false;
	}
	else if (b.getSize() != 0)
	{
		cout << "testBarCharParameterizedConstructor: Parameterized Constructor getSize() 'FAILED'" << endl;
		return false;
	}
	cout << "testBarCharParameterizedConstructor: all passed!" << endl;
	return true;
}

bool testBarChartCopyConstructor()
{
	// need to have value
	BarChart b(10); // calling the Parameterized constructor so all the values get assign
	BarChart bc(b); // use for the test

	if (b.getBars() == bc.getBars())
	{
		cout << "testBarChartCopyConstructor: Copy Constructor 'getBars()' 'FAILED'" << endl;
		return false;
	}
	else if (b.getSize() != bc.getSize())
	{
		cout << "testBarChartCopyConstructor: Copy Constructor 'getSize()' 'FAILED'" << endl;
		return false;
	}
	else if (b.getCapacity() != bc.getCapacity())
	{
		cout << "testBarChartCopyConstructor: Copy Constructor 'getCapacity()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartCopyConstructor: all passed!" << endl;
	return true;
}

bool testBarChartEqualOperator()
{
	BarChart emtpyB;
	BarChart valueB(5);

	emtpyB = valueB; // using '=' operator

	if (emtpyB.getBars() == valueB.getBars())
	{
		cout << "testBarChatEqualOperator: Equal(=) Operator 'getBars()' 'FAILED'" << endl;
		return false;
	}
	else if (emtpyB.getSize() != valueB.getSize())
	{
		cout << "testBarChatEqualOperator: Equal(=) Operator 'getSize()' 'FAILED'" << endl;
		return false;
	}
	else if (emtpyB.getCapacity() != valueB.getCapacity())
	{
		cout << "testBarChatEqualOperator: Equal(=) Operator 'getCapacity()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChatEqualOperator: all passed!" << endl;
	return true;
}

bool testBarChartClean()
{
	BarChart b1(10);
	b1.clear();
	if (b1.getBars() != nullptr)
	{
		cout << "testBarChartClean: clean(). the 'getBars()' 'FAILED'" << endl;
		return false;
	}
	else if (b1.getCapacity() != 0)
	{
		cout << "testBarChartClean: clean(). the 'getCapacity()' 'FAILED'" << endl;
		return false;
	}
	else if (b1.getSize() != 0)
	{
		cout << "testBarChartClean: clean(). the 'getSize()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartClean: all passed!" << endl;
	return true;
}

bool testBarChartGetFrameAndSetFrame()
{
	BarChart bc;
	bc.setFrame("1950");
	if (bc.getFrame() != "1950")
	{
		cout << "testBarChartGetFrameAndSetFrame: 'getFrame()' or  'setFrame() ''FAILED'" << endl;
		return false;
	}
	cout << "testBarChartGetFrameAndSetFrame: all passed!" << endl;
	return true;
}

bool testBarChartAddBar()
{
	BarChart bc(3);
	bool test1 = bc.addBar("Chicago", 1020, "US");
	bool test2 = bc.addBar("NYC", 1300, "US");
	bool test3 = bc.addBar("Paris", 1200, "France");
	bool test4 = bc.addBar("Paris", 1200, "France"); // max reached
	if (!test1)
	{
		cout << "testBarChartAddBar: 'addBar()' 'FAILED'" << endl;
		return false;
	}
	else if (!test2)
	{
		cout << "testBarChartAddBar: 'addBar()' 'FAILED'" << endl;
		return false;
	}
	else if (!test3)
	{
		cout << "testBarChartAddBar: 'addBar()' 'FAILED'" << endl;
		return false;
	}
	else if (test4)
	{
		cout << "testBarChartAddBar: 'addBar()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartAddBar: all passed!" << endl;
	return true;
}

bool testBarChartBracketOperator()
{
	int n = 3;
	BarChart bc(n);
	bool test1 = bc.addBar("Chicago", 1020, "US");

	if (bc[0].getName() != "Chicago")
	{
		cout << "testBarChartBracketOperator: 'getName()' 'FAILED'" << endl;
		return false;
	}
	else if (bc[0].getValue() != 1020)
	{
		cout << "testBarChartBracketOperator: 'getValue()' 'FAILED'" << endl;
		return false;
	}
	else if (bc[0].getCategory() != "US")
	{
		cout << "testBarChartBracketOperator: 'getCategory()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartBracketOperator: all passed!" << endl;
	return true;
}

bool testBarChartDump()
{
	BarChart bc(3);
	string line;
	stringstream ss(line);
	bc.setFrame("1950");
	bool test1 = bc.addBar("Chicago", 1020, "US");
	bool test2 = bc.addBar("NYC", 1300, "US");
	bool test3 = bc.addBar("Paris", 1200, "France");
	bc.dump(ss);
	getline(ss, line);
	if (line != "frame: 1950")
	{
		cout << "testBarChartDump: '" << line << "' 'FAILED'" << endl;
		return false;
	}
	getline(ss, line);
	if (line != "NYC 1300 US")
	{
		cout << "testBarChartDump: '" << line << "' 'FAILED'" << endl;
		return false;
	}
	getline(ss, line);
	if (line != "Paris 1200 France")
	{
		cout << "testBarChartDump: '" << line << "' 'FAILED'" << endl;
		return false;
	}
	getline(ss, line);
	if (line != "Chicago 1020 US")
	{
		cout << "testBarChartDump: '" << line << "' 'FAILED'" << endl;
		return false;
	}
	cout << "testBarChartDump: all passed!" << endl;
	return true;
}

bool testBarChartGraph()
{
	BarChart bc(14);
	map<string, string> colorMap;
	bc.setFrame("1950");
	bool test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test12,
		test11, test13, test14, test15;
	test1 = bc.addBar("Paris", 1200, "France");
	test2 = bc.addBar("Chicago", 1020, "US");
	test3 = bc.addBar("NYC", 1300, "US");
	test4 = bc.addBar("China", 672, "East Asia");
	test5 = bc.addBar("Egypt", 400, "Middle East");
	test6 = bc.addBar("India", 140, "South Asia");
	test7 = bc.addBar("Morocco", 130, "Middle East");
	test8 = bc.addBar("India", 250, "South Asia");
	test9 = bc.addBar("China", 150, "East Asia");
	test10 = bc.addBar("China", 250, "East Asia");
	test11 = bc.addBar("Turkey", 200, "Europe");
	test12 = bc.addBar("China", 147, "East Asia");
	test13 = bc.addBar("France", 185, "Europe");
	test14 = bc.addBar("Iran", 250, "Middle East");
	test15 = bc.addBar("India", 500, "South Asia");
	colorMap["US"] = "";
	colorMap["France"] = BLUE;
	colorMap["East Asia"] = CYAN;
	colorMap["Europe"] = GREEN;
	colorMap["South Asia"] = GOLD;
	colorMap["Middle East"] = PURPLE;
	if (bc.getFrame() != "1950")
	{
		cout << "testBarChartGraph: '1950' 'FAILED'" << endl;
		return false;
	}
	else if (!colorMap.count("US"))
	{
		cout << "testBarChartGraph: 'FAILED'. US Not Found." << endl;
		return false;
	}
	else if (!colorMap.count("France"))
	{
		cout << "testBarChartGraph: 'FAILED'. US Not Found." << endl;
		return false;
	}
	else if (!colorMap.count("Europe"))
	{
		cout << "testBarChartGraph: 'FAILED'. US Not Found." << endl;
		return false;
	}
	else if (!colorMap.count("South Asia"))
	{
		cout << "testBarChartGraph: 'FAILED'. US Not Found." << endl;
		return false;
	}
	else if (!colorMap.count("Middle East"))
	{
		cout << "testBarChartGraph: 'FAILED'. US Not Found." << endl;
		return false;
	}
	cout << "testBarChartGraph: all passed!" << endl;
	return true;
}

bool testBcaParameterizedConstructor()
{

	string title = "Patents granted by applicants country of origin from 1980 to 2018";
	string xlabel = "Patents";
	string source = "WIPO";
	BarChartAnimate bc(title, xlabel, source);
	if (bc.getTitle() != title)
	{
		cout << "testBcaParameterizedConstructor: 'title' 'FAILED'" << endl;
		return false;
	}
	else if (bc.getXlable() != xlabel)
	{
		cout << "testBcaParameterizedConstructor: 'xlabel' 'FAILED'" << endl;

		return false;
	}
	else if (bc.getSource() != source)
	{
		cout << "testBcaParameterizedConstructor: 'source' 'FAILED'" << endl;
		return false;
	}
	cout << "testBcaParameterizedConstructor: all passed!" << endl;
}

bool testBcaAddBar()
{
	ifstream inFile("cities.txt");
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	for (int i = 0; i < 5; i++)
		bca.addFrame(inFile);

	if (bca.getSize() != 5)
	{
		cout << "testBcaParameterizedConstructor: 'getSize()' 'FAILED'" << endl;
		return false;
	}
	else if (bca.getCapacity() != 8)
	{
		cout << "testBcaParameterizedConstructor: 'getgetCapacity()' 'FAILED'" << endl;
		return false;
	}
	cout << "testBcaAddBar: all passed!" << endl;
	return true;
}

bool testBcaAnimate()
{
	ifstream inFile("cities.txt");
	string title, xlabel, source, line;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	for (int i = 0; i < 5; i++)
		bca.addFrame(inFile);

	if (bca[0].getFrame() != "1500")
	{
		cout << "testBcaAnimate: 'getFrame() --> 1500' 'FAILED'" << endl;
		return false;
	}
	else if (bca[1].getFrame() != "1501")
	{
		cout << "testBcaAnimate: 'getFrame() --> 1501' 'FAILED'" << endl;
		return false;
	}
	else if (bca[2].getFrame() != "1502")
	{
		cout << "testBcaAnimate: 'getFrame() --> 1502' 'FAILED'" << endl;
		return false;
	}
	else if (bca[3].getFrame() != "1503")
	{
		cout << "testBcaAnimate: 'getFrame() --> 1503' 'FAILED'" << endl;
		return false;
	}
	else if (bca[4].getFrame() != "1504")
	{
		cout << "testBcaAnimate: 'getFrame() --> 1504' 'FAILED'" << endl;
		return false;
	}
	cout << "testBcaAnimate: all passed!" << endl;
	return true;
}

bool testAllHFileSizeAndCapacity(BarChartAnimate &bca, ifstream &file)
{
	for (int i = 0; i < 10; i++)
		bca.addFrame(file);

	if (bca.getCapacity() != 16)
	{
		cout << "TEST_ALL_H_FILES: 'getCapacity()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	else if (bca.getSize() != 10)
	{
		cout << "TEST_ALL_H_FILES: 'getSize()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	else if (bca[0].getFrame() != "S1E01 0:01")
	{
		cout << "TEST_ALL_H_FILES: 'getFrame()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	else if (bca[4].getFrame() != "S1E01 0:05")
	{
		cout << "TEST_ALL_H_FILES: 'getFrame()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	else if (bca[9].getFrame() != "S1E01 0:12")
	{
		cout << "TEST_ALL_H_FILES: 'getFrame()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	return true;
}

bool testAllHFilewholeFile(BarChartAnimate &bca, ifstream &file, int size)
{
	if (bca.getSize() != size - 1)
	{
		cout << "TEST_ALL_H_FILES: 'getSize()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	else if (bca[bca.getSize() - 1].getFrame() != "S8E06 1:20")
	{
		cout << bca[bca.getSize() - 1].getFrame() << endl;
		cout << "TEST_ALL_H_FILES: 'getFrame()' 'FAILED' after adding multiple frames" << endl;
		return false;
	}
	string data, testFrame;
	stringstream ss(data);
	bca[1000].dump(ss);
	getline(ss, testFrame, '\n');
	if (testFrame != "frame: S2E10 0:16")
	{
		cout << "TEST_ALL_H_FILES: 'FAILED' after dumping frames" << endl;
		return false;
	}
	for (int i = 0; i < 109; i++)
	{
		getline(ss, testFrame, '\n');
	}
	if (testFrame != "Amory Lorch 406 Other")
	{
		cout << "TEST_ALL_H_FILES: 'FAILED' after dumping frames" << endl;
		return false;
	}
	return true;
}

bool Test_All_H_FILES()
{
	string testTitle = "Most popular characters in Game of Thrones",
		   testXLable = "Screen time (seconds)",
		   testSource = "Source: IMDB";
	ifstream inFile("game-of-thrones.txt");
	string title, xlabel, source, line;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	if (bca.getCapacity() != 4)
	{
		cout << "TEST_ALL_H_FILES: 'getCapacity()' 'FAILED'" << endl;
		return false;
	}
	else if (bca.getSize() != 0)
	{
		cout << "TEST_ALL_H_FILES: 'getsize()' 'FAILED'" << endl;
		return false;
	}
	else if (bca.getTitle() != testTitle)
	{
		cout << "TEST_ALL_H_FILES: 'getTitle()' 'FAILED'" << endl;
		return false;
	}
	else if (bca.getXlable() != testXLable)
	{
		cout << "TEST_ALL_H_FILES: 'getXlable()' 'FAILED'" << endl;
		return false;
	}
	else if (bca.getSource() != testSource)
	{
		cout << "TEST_ALL_H_FILES: 'getSource()' 'FAILED'" << endl;
		return false;
	}
	// lets add few thing inside of our bars and see if the size and capacity changes
	bool sizeAndCap = testAllHFileSizeAndCapacity(bca, inFile);
	// read all the file data:
	int size = 10;
	while (!inFile.eof())
	{
		bca.addFrame(inFile);
		size++;
	}
	bool allDataOfGFT = testAllHFilewholeFile(bca, inFile, size);
	if (sizeAndCap && allDataOfGFT)
		;
	cout << "TEST_ALL_H_FILES: all passed!" << endl;
	return true;
}

int main()
{
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarOperators();
	testBarChartDefaultConstructor();
	testBarChartParameterizedConstructor();
	testBarChartCopyConstructor();
	testBarChartEqualOperator();
	testBarChartClean();
	testBarChartGetFrameAndSetFrame();
	testBarChartAddBar();
	testBarChartBracketOperator();
	testBarChartDump();
	testBarChartGraph();
	testBcaParameterizedConstructor();
	testBcaAddBar();
	testBcaAnimate();
	Test_All_H_FILES();

	return 0;
}