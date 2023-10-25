#include"Init.h"
#include"ANS.h"
void ReadData(std::string SetName,vector<ANS>& data)
{
	data.clear();
	string filepath = "./DataSets/toone/" + SetName + ".xlsx";
	XLDocument doc = XLDocument();
	doc.open(filepath);
	cout << doc.isOpen() << endl;
	auto wkbook = doc.workbook();
	auto sheet = wkbook.worksheet("Sheet1");
	int m = sheet.columnCount(), n = sheet.rowCount();
	cout << n << " " << m << endl;
	for (int i = 2; i <= n; i++)
	{
		ANS nowv(m-1);
		ld t = 0;
		for (int j = 2; j <= m; j++)
		{
			try {
				t = sheet.cell(i, j).value();
			}
			catch (exception ex){
				try {
					int l = sheet.cell(i, j).value();
					t = l;
				}
				catch (exception ex2) {
					cout << ex2.what() << endl;
				}
			}
			nowv[j - 2] = (ld)t;
		}
		data.push_back(nowv);
	}
	int cnt = 0;
	for (auto v : data)
	{
		cout << ++cnt << " "; v.print();
	}
}