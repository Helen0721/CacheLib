PID=73621 # Replace with your PID
INTERVAL=1
DURATION=60
COUNT=$((DURATION / INTERVAL))

total_cpu=0

for (( i=0; i<COUNT; i++ )); do
  CPU_USAGE=$(top -b -n 1 -p $PID | grep $PID | awk '{print $9}')
  total_cpu=$(echo "$total_cpu + $CPU_USAGE" | bc)
  sleep $INTERVAL
done

average_cpu=$(echo "scale=2; $total_cpu / $COUNT" | bc)
echo "Average CPU Usage over $DURATION seconds: $average_cpu%"
