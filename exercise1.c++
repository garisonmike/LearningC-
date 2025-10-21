// calculating tax
#include <iostream>

int main() {
  using namespace std;

  double sales = 95000;
  const double stateTax = 0.04;
  const double countyTax = 0.02;
  double totalTax = 0;
  double netSales = 0;
  double stateTaxPayable = 0;
  double countyTaxPayable = 0;

  stateTaxPayable = stateTax * sales;
  countyTaxPayable = countyTax * sales;
  totalTax = stateTaxPayable + countyTaxPayable;
  netSales = (sales - totalTax);

  cout << "The sales you make are $" << sales << endl;
  cout << "The state tax you're required to pay is $" << stateTaxPayable
       << " and county tax $" << countyTaxPayable << endl;
  cout << "The total tax you're supposed to pay is $" << totalTax << endl;
  cout << "The net Sales you remain with is $" << netSales << endl;

  return 0;
}