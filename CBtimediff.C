using namespace std;

void CBtimediff(char name[100], Bool_t GPIO5_ON = 0, Bool_t GPIO22_ON = 1, Bool_t GPIO23_ON = 1, Bool_t GPIO24_ON = 1)
{
  Int_t depth;
  if(name == "events_20181123-093751") depth = 0;
  else if(name == "events_20181123-113012") depth = -174;
  else if(name == "events_20181126-114234") depth = -339;
  else if(name == "events_20181205-113029") depth = -512;
  else if(name == "events_20181213-094256") depth = -513; //always same depht (512), just to distinush them easily
  else if(name == "events_20181231-091501") depth = -514; //always same depht (512), just to distinush them easily
  else if(name == "512_merge") depth = -512;
  else depth = 9999;
  

  Double_t cutOnTime[4][3]; //[i][0] depth, [i][1] start time, [i][2] end time
  cutOnTime[0][0] = 512; cutOnTime[0][1] = 1546 * 1e9; cutOnTime[0][2] = 1546.3 * 1e9;
  cutOnTime[1][0] = 512; cutOnTime[1][1] = 1546.5 * 1e9; cutOnTime[1][2] = 1546.65 * 1e9;
  cutOnTime[2][0] = 512; cutOnTime[2][1] = 1547.6 * 1e9; cutOnTime[2][2] = 1548.3 * 1e9;
  cutOnTime[3][0] = 512; cutOnTime[3][1] = 1550.6 * 1e9; cutOnTime[3][2] = 1551.3 * 1e9;

  
  
  TCut cutOnCB = 0;
  if(!GPIO5_ON) cutOnCB += "GPIO != 5";
  if(!GPIO22_ON) cutOnCB += "GPIO != 22";
  if(!GPIO23_ON) cutOnCB += "GPIO != 23";
  if(!GPIO24_ON) cutOnCB += "GPIO != 24";

  TCut TimeCut = Form("(time < %f || time > %f) && (time < %f || time > %f) && (time < %f || time > %f) && (time < %f || time > %f)", cutOnTime[0][1], cutOnTime[0][2], cutOnTime[1][1], cutOnTime[1][2], cutOnTime[2][1], cutOnTime[2][2], cutOnTime[3][1], cutOnTime[3][2]);
  //TCut TimeCut = 0;
  
  TFile *file = new TFile(Form("%s.root", name));
  TTree *tree[5],*temptree[5];
  gROOT->cd();
  temptree[0] = (TTree*) file->Get("tot");
  temptree[1] = (TTree*) file->Get("GPIO5");
  temptree[2] = (TTree*) file->Get("GPIO22");
  temptree[3] = (TTree*) file->Get("GPIO23");
  temptree[4] = (TTree*) file->Get("GPIO24");

  temptree[0]->Draw(">>selected", cutOnCB + TimeCut);
  TEventList *list = (TEventList*)gDirectory->Get("selected");
  temptree[0]->SetEventList(list);
  tree[0] = temptree[0]->CopyTree("");

  temptree[1]->Draw(">>selected", TimeCut);
  TEventList *list = (TEventList*)gDirectory->Get("selected");
  temptree[1]->SetEventList(list);
  tree[1] = temptree[1]->CopyTree("");

  temptree[2]->Draw(">>selected", TimeCut);
  TEventList *list = (TEventList*)gDirectory->Get("selected");
  temptree[2]->SetEventList(list);
  tree[2] = temptree[2]->CopyTree("");

  temptree[3]->Draw(">>selected", TimeCut);
  TEventList *list = (TEventList*)gDirectory->Get("selected");
  temptree[3]->SetEventList(list);
  tree[3] = temptree[3]->CopyTree("");

  temptree[4]->Draw(">>selected", TimeCut);
  TEventList *list = (TEventList*)gDirectory->Get("selected");
  temptree[4]->SetEventList(list);
  tree[4] = temptree[4]->CopyTree("");
  
  
  Int_t GPIO; Double_t time0, time1, time2, time3, time4;
  tree[0]->SetBranchAddress("GPIO", &GPIO);
  tree[0]->SetBranchAddress("time", &time0);
  
  tree[1]->SetBranchAddress("time", &time1);
  tree[2]->SetBranchAddress("time", &time2);
  tree[3]->SetBranchAddress("time", &time3);
  tree[4]->SetBranchAddress("time", &time4);
  
  
  cout << std::setprecision(18);
  
  Int_t nent = tree[0]->GetEntries();
  tree[0]->GetEntry(nent-1);
  Double_t t_acq = time0;
  Double_t t_end = time0;
  cout << endl << endl << t_acq << endl << endl;
  tree[0]->GetEntry(0);
  t_acq -= time0;
  cout << time0 << endl << endl;

  if(depth == (int)cutOnTime[0][0])
  {
    if(cutOnTime[0][1] < time0) cutOnTime[0][1] = time0;
    if(cutOnTime[3][2] > t_end) cutOnTime[3][2] = t_end;
    
    t_acq -= TMath::Abs(cutOnTime[0][2] - cutOnTime[0][1]);
    t_acq -= TMath::Abs(cutOnTime[1][2] - cutOnTime[1][1]);
    t_acq -= TMath::Abs(cutOnTime[2][2] - cutOnTime[2][1]);
    t_acq -= TMath::Abs(cutOnTime[3][2] - cutOnTime[3][1]);
  }

  t_acq *= 1e-3;
  
  
  cout << endl << endl << "Acquisition time = " << t_acq/3600 << " hour"<< endl << endl;
  
  Double_t rate[5][3]; //0 valore 1 errore 2 significatività
  rate[0][0] = tree[0]->GetEntries()/t_acq;
  rate[1][0] = tree[1]->GetEntries()/t_acq;
  rate[2][0] = tree[2]->GetEntries()/t_acq;
  rate[3][0] = tree[3]->GetEntries()/t_acq;
  rate[4][0] = tree[4]->GetEntries()/t_acq;
  
  rate[0][1] = TMath::Sqrt(tree[0]->GetEntries())/t_acq;
  rate[1][1] = TMath::Sqrt(tree[1]->GetEntries())/t_acq;
  rate[2][1] = TMath::Sqrt(tree[2]->GetEntries())/t_acq;
  rate[3][1] = TMath::Sqrt(tree[3]->GetEntries())/t_acq;
  rate[4][1] = TMath::Sqrt(tree[4]->GetEntries())/t_acq;
  
  rate[0][2] = TMath::Sqrt(tree[0]->GetEntries())/tree[0]->GetEntries();
  rate[1][2] = TMath::Sqrt(tree[1]->GetEntries())/tree[1]->GetEntries();
  rate[2][2] = TMath::Sqrt(tree[2]->GetEntries())/tree[2]->GetEntries();
  rate[3][2] = TMath::Sqrt(tree[3]->GetEntries())/tree[3]->GetEntries();
  rate[4][2] = TMath::Sqrt(tree[4]->GetEntries())/tree[4]->GetEntries();
  
  
  Float_t sup[5];
  sup[0] = 10 / rate[0][0];
  sup[1] = 10 / rate[1][0];
  sup[2] = 10 / rate[2][0];
  sup[3] = 10 / rate[3][0];
  sup[4] = 10 / rate[4][0];
  
  
  TH1F *hdiff[5];
  hdiff[0] = new TH1F("hdiff", "hdiff", 40, 0, sup[0]);
  hdiff[1] = new TH1F("GPIO_5", "GPIO_5", 40, 0, sup[1]);
  hdiff[2] = new TH1F("GPIO_22", "GPIO_2", 40, 0, sup[2]);
  hdiff[3] = new TH1F("GPIO_23", "GPIO_23", 40, 0, sup[3]);
  hdiff[4] = new TH1F("GPIO_24", "GPIO_24", 40, 0, sup[4]);
  
  
  TGraph *diff_time[5];
  for(int i = 0; i < 5; i++) diff_time[i] = new TGraph();
  
  
  tree[0]->GetEntry(0);
  Double_t t_start = time0;
  
  Double_t t_diff, t_mean;
  for(int i = 0; i < tree[0]->GetEntries(); i++)
    {
      tree[0]->GetEntry(i);
      t_diff = time0;
      t_mean = time0;
      
      tree[0]->GetEntry(i-1);
      t_diff -= time0;
      t_diff *= 1e-3;
      t_mean += time0;
      t_mean -= 2*t_start;
      t_mean /= 2;
      
      hdiff[0]->Fill(t_diff);
      diff_time[0]->SetPoint(i, t_mean, t_diff);
    }
  
  for(int i = 0; i < tree[1]->GetEntries(); i++)
    {
      tree[1]->GetEntry(i);
      t_diff = time1;
      t_mean = time1;
      
      tree[1]->GetEntry(i-1);
      t_diff -= time1;
      t_diff *= 1e-3;
      t_mean += time1;
      t_mean -= 2*t_start;
      t_mean /= 2;
      
      hdiff[1]->Fill(t_diff);
      diff_time[1]->SetPoint(i, t_mean, t_diff);
    }
  
  for(int i = 0; i < tree[2]->GetEntries(); i++)
    {
      tree[2]->GetEntry(i);
      t_diff = time2;
      t_mean = time2;
      
      tree[2]->GetEntry(i-1);
      t_diff -= time2;
      t_diff *= 1e-3;
      t_mean += time2;
      t_mean -= 2*t_start;
      t_mean /= 2;
      
      hdiff[2]->Fill(t_diff);
      diff_time[2]->SetPoint(i, t_mean, t_diff);
    }
  
  for(int i = 0; i < tree[3]->GetEntries(); i++)
    {
      tree[3]->GetEntry(i);
      t_diff = time3;
      t_mean = time3;
      
      tree[3]->GetEntry(i-1);
      t_diff -= time3;
      t_diff *= 1e-3;
      t_mean += time3;
      t_mean -= 2*t_start;
      t_mean /= 2;
      
      hdiff[3]->Fill(t_diff);
      diff_time[3]->SetPoint(i, t_mean, t_diff);
    }
  
  for(int i = 0; i < tree[4]->GetEntries(); i++)
    {
      tree[4]->GetEntry(i);
      t_diff = time4;
      t_mean = time4;
      
      tree[4]->GetEntry(i-1);
      t_diff -= time4;
      t_diff *= 1e-3;
      t_mean += time4;
      t_mean -= 2*t_start;
      t_mean /= 2;
      
      hdiff[4]->Fill(t_diff);
      diff_time[4]->SetPoint(i, t_mean, t_diff);
    }
  
  
  
  cout << endl << endl;
  cout << "rate tot = " << rate[0][0] << " +/- " << rate[0][1] << " Hz  -  sign = " << rate[0][2] << endl;
  if(GPIO5_ON) cout << "rate CB4 = " << rate[1][0] << " +/- " << rate[1][1] << " Hz  -  sign = " << rate[1][2] << endl;
  if(GPIO22_ON) cout << "rate CB7 = " << rate[2][0] << " +/- " << rate[2][1] << " Hz  -  sign = " << rate[2][2] << endl;
  if(GPIO23_ON) cout << "rate CB11 = " << rate[3][0] << " +/- " << rate[3][1] << " Hz  -  sign = " << rate[3][2] << endl;
  if(GPIO24_ON) cout << "rate CB14 = " << rate[4][0] << " +/- " << rate[4][1] << " Hz  -  sign = " << rate[4][2] << endl;
  cout << endl;
  
  
  TF1 *exp[5];
  
  for(int i = 0; i < 5; i++)
    {
      exp[i]= new TF1(Form("exp%d", i), "[0]*exp(-[1]*x)", 0, sup[i]);
      exp[i]->SetParameters(100, rate[i][0]);
      exp[i]->SetParName(0, "N");
      exp[i]->SetParName(1, "#lambda");
    }
  
  gStyle->SetOptFit(1);
  gStyle->SetOptStat("emr");

  
  TLatex *pre = new TLatex(0.3,0.85,"Preliminary");
  pre->SetTextSize(0.05*1.2);
  pre->SetTextFont(42);
  pre->SetTextColor(kRed);
  pre->SetNDC(1);
  pre->SetTextAlign(13);
  
  
  TCanvas *c[5];
  
  c[0] = new TCanvas();
  c[0]->SetLogy();
  hdiff[0]->Fit(exp[0],"","GOFF");
  hdiff[0]->SetTitle(Form("Full statistics (%d m below ground level); Time difference [s]; Events / %.2f s", depth, hdiff[0]->GetBinWidth(1)));
  hdiff[0]->Draw();
  //pre->Draw("SAME");
  c[0]->SaveAs(Form("./graphs/time_diff %d meters.png", depth));
  
  
  if(GPIO5_ON)
    {
      c[1] = new TCanvas();
      c[1]->SetLogy();
      hdiff[1]->Fit(exp[1],"","GOFF");
      hdiff[1]->SetTitle(Form("Cosmic Box 4 (%d m below ground level); Time difference [s]; Events / %.2f s", depth, hdiff[1]->GetBinWidth(1))); //GPIO5
      hdiff[1]->Draw();
      //pre->Draw("SAME");
      c[1]->SaveAs(Form("./graphs/time_diff %d meters CB4.png", depth));
    }
  
  if(GPIO22_ON)
    {
      c[2] = new TCanvas();
      c[2]->SetLogy();
      hdiff[2]->Fit(exp[2],"","GOFF");
      hdiff[2]->SetTitle(Form("Cosmic Box 7 (%d m below ground level); Time difference [s]; Events / %.2f s", depth, hdiff[2]->GetBinWidth(1))); //GPIO22
      hdiff[2]->Draw();
      //pre->Draw("SAME");
      c[2]->SaveAs(Form("./graphs/time_diff %d meters CB7.png", depth));
      
    }
  
  if(GPIO23_ON)
    {
      c[3] = new TCanvas();
      c[3]->SetLogy();
      hdiff[3]->Fit(exp[3],"","GOFF");
      hdiff[3]->SetTitle(Form("Cosmic Box 11 (%d m below ground level); Time difference [s]; Events / %.2f s", depth, hdiff[3]->GetBinWidth(1))); //GPIO23
      hdiff[3]->Draw();
      //pre->Draw("SAME");
      c[3]->SaveAs(Form("./graphs/time_diff %d meters CB11.png", depth));
      
    }
  
  if(GPIO24_ON)
    {
      c[4] = new TCanvas();
      c[4]->SetLogy();
      hdiff[4]->Fit(exp[4],"","GOFF");
      hdiff[4]->SetTitle(Form("Cosmic Box 14 (%d m below ground level); Time difference [s]; Events / %.2f s", depth, hdiff[4]->GetBinWidth(1))); //GPIO24
      hdiff[4]->Draw();
      //pre->Draw("SAME");
      c[4]->SaveAs(Form("./graphs/time_diff %d meters CB14.png", depth));
      
    }

  tree[0]->GetEntry(0);
  Double_t timestart = time0;
  TH1F *htimestamp0 = new TH1F("htimestamp0", "Counts w.r.t. time", 60, -5, t_acq*60/(3.6*1e3) + 5); //, timestart - 1e8, timestart + t_acq*1e3 + 1e8);
  TH1F *htimestamp1 = new TH1F("htimestamp1", "Timestamps full CB4", 40, -20, t_acq/(3.6*1e3) + 20); //, timestart - 1e9, timestart + t_acq*1e3 + 1e9);
  TH1F *htimestamp2 = new TH1F("htimestamp2", "Timestamps full CB7", 40, -20, t_acq/(3.6*1e3) + 20); //, timestart - 1e9, timestart + t_acq*1e3 + 1e9);
  TH1F *htimestamp3 = new TH1F("htimestamp3", "Timestamps full CB11", 40, -20, t_acq/(3.6*1e3) + 20); //, timestart - 1e9, timestart + t_acq*1e3 + 1e9);
  TH1F *htimestamp4 = new TH1F("htimestamp4", "Timestamps full CB14", 40, -20, t_acq/(3.6*1e3) + 20); //, timestart - 1e9, timestart + t_acq*1e3 + 1e9);

  
  TCanvas *c2 = new TCanvas();
  //diff_time[0]->Draw("AP");
  tree[0]->Draw(Form("(time-%f)*60/(3.6*1e6)>>htimestamp0",timestart), cutOnCB);
  htimestamp0->GetXaxis()->SetTitle("Time from acquisition start (min)");
  htimestamp0->GetYaxis()->SetTitle(Form("Counts / %.2f min", htimestamp0->GetBinWidth(1)*60)); /// 3.6 * 1e-6));
  htimestamp0->GetYaxis()->SetTitleOffset(1.2);
  htimestamp0->SetStats(0);
  c2->SaveAs(Form("./graphs/timestamp_%d.png",depth));
  

  if(GPIO5_ON)
    {
      TCanvas *c3 = new TCanvas();
      //diff_time[1]->Draw("AP");
      tree[1]->Draw(Form("(time-%f)/(3.6*1e6)>>htimestamp1",timestart));
      //htimestamp1->SetMaximum(15);
      htimestamp1->GetXaxis()->SetTitle("Time from acquisition start (min)");
      htimestamp1->GetYaxis()->SetTitle(Form("Counts / %.2f hr", htimestamp1->GetBinWidth(1) / 3.6 * 1e-6));
      htimestamp1->SetStats(0);
      c3->SaveAs(Form("./graphs/timestamp_%d_CB4.png",depth));
    }

    if(GPIO22_ON)
    {
      TCanvas *c4 = new TCanvas();
      //diff_time[2]->Draw("AP");
      tree[2]->Draw(Form("(time-%f)/(3.6*1e6)>>htimestamp2",timestart));
      //htimestamp2->SetMaximum(15);
      htimestamp2->GetXaxis()->SetTitle("Time from acquisition start (hr)");
      htimestamp2->GetYaxis()->SetTitle(Form("Counts / %.2f hr", htimestamp2->GetBinWidth(1) / 3.6 * 1e-6));
      htimestamp2->SetStats(0);
      c4->SaveAs(Form("./graphs/timestamp_%d_CB7.png",depth));
    }
    
  if(GPIO23_ON)
    {
      TCanvas *c5 = new TCanvas();
      //diff_time[3]->Draw("AP");
      tree[3]->Draw(Form("(time-%f)/(3.6*1e6)>>htimestamp3",timestart));
      //htimestamp3->SetMaximum(15);
      htimestamp3->GetXaxis()->SetTitle("Time from acquisition start (hr)");
      htimestamp3->GetYaxis()->SetTitle(Form("Counts / %.2f hr", htimestamp3->GetBinWidth(1) / 3.6 * 1e-6));
      htimestamp3->SetStats(0);
      c5->SaveAs(Form("./graphs/timestamp_%d_CB11.png",depth));
    }
  
  if(GPIO24_ON)
    {
      TCanvas *c6 = new TCanvas();
      //diff_time[4]->Draw("AP");
      tree[4]->Draw(Form("(time-%f)/(3.6*1e6)>>htimestamp4",timestart));
      //htimestamp4->SetMaximum(15);
      htimestamp4->GetXaxis()->SetTitle("Time from acquisition start (hr)");
      htimestamp4->GetYaxis()->SetTitle(Form("Counts / %.2f hr", htimestamp4->GetBinWidth(1) / 3.6 * 1e-6));
      htimestamp4->SetStats(0);
      c6->SaveAs(Form("./graphs/timestamp_%d_CB14.png",depth));
    }
}
