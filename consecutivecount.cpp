int flag = 0;
		
		if (v[0] < 0)
		{
			flag =1;
		}
		long long int sum = 0;
		long long int h=0;
		long long int index=0;
		for(long long int i=0; i<v.size();i++)
		{
			if (flag == 0)
			{
				if (v[i] > 0)
				{
					sum = sum + v[i];				
				}
				else
				{
					s.push_back(sum);
					if(sum>h)
					{
						h=sum;
						index=i;
					}
					sum =0;
					sum = sum + v[i];
					flag = 1;
				}
			}
			
			else
			{
				if (v[i] < 0)
				{
					sum = sum + v[i];
				}
				
				else
				{
					s.push_back(sum);
					if(sum>h)
					{
						h=sum;
						index=i;
					}
					sum = 0;
					sum = sum + v[i];
					flag = 0;
				}
			}
		}
		
		s.push_back(sum);
