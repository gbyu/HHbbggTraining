void find_best_optim_param()
{
    float row[1000];
    vector<float> vec_res;
    const string DIR_RES = "/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2019-10-02_optimization_job/results_2019-10-02_optimization_job.txt";
    string f_res;
    ostringstream o_str_f;
    o_str_f << DIR_RES;
    f_res = o_str_f.str(); o_str_f.str("");
    FILE *pF;
    pF=fopen(f_res.c_str(), "r");
    for (int k=0; k<12; k++)
    {
      fscanf(pF," %f",&row[k]);
      cout<<k<<"\t"<<row[k]<<endl;
      vec_res.push_back(row[k]);
    } 
    fclose(pF);
    cout<<"Best score:"<<"\t"<<setprecision(5)<<*max_element(vec_res.begin(),vec_res.end())<<endl;
}
