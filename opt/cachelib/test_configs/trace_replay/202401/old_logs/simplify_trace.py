import pandas as pd

for i in range(1,6):
    print("Cleanning",i,end="...")
    df = pd.read_csv('kvcache_traces_{}.csv'.format(i))
    filtered_df = df[df['op'] != 'delete']
    filtered_df.to_csv('kvcache_traces_{}_SET.csv'.format(i), index=False)
    print("done")
