void Compare()
{
  TF1 *flux = new TF1("flux", "[0] * (([1]/x)**[2]) * exp(-x/[1])", 0, 5000);
  TF1 *flux_err = new TF1("flux_err", "((((x/[1])**[2]) * exp(-x/[1]) * [3])**2) + (([0] * log([1]/x) * (([1]/x)**[2]) * exp(-x/[1]) * [5])**2) + ((([0] * (([1]/x)**[2]) * exp(-x/[1])) * (([2]/[1]) + (x/[1])) * [4])**2)", 0, 5000);
  TF1 *flux_err_pos = new TF1("flux_err_pos", "flux + flux_err", 0, 5000);
  TF1 *flux_err_neg = new TF1("flux_err_neg", "flux - flux_err", 0, 5000);

  flux->SetParameters(0.025, 1330, 2.18);
  flux_err_pos->SetParameters(0.025, 1330, 2.18, 0.004, 140, 0.12);
  flux_err_neg->SetParameters(0.025, 1330, 2.18, 0.004, 140, 0.12);

  flux->Draw();

  flux_err_pos->SetLineColor(kBlue);
  flux_err_pos->SetLineStyle(2);
  flux_err_pos->Draw("SAME");

  flux_err_neg->SetLineColor(kBlack);
  flux_err_neg->SetLineStyle(2);
  flux_err_neg->Draw("SAME");

}
