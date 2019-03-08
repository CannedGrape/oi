var
  n,m,q,i,j,t,a,b,k:longint;
  ways:array[1..10000,1..10000] of longint;
  trun:array[1..50000,1..2] of longint;

begin

  assign( input,'truck.in' ); reset(input);
  assign( output,'truck.out' ); rewrite(output);

  fillchar( ways,sizeof(ways),0 );

  readln( n,m );

  for i:=1 to m do begin
    readln( a,b,t );
    if t > ways[a,b] then begin
      ways[a,b]:=t;
      ways[b,a]:=t;
    end;
  end;

  readln( k );

  for i:=1 to k do
    readln(trun[i,1],trun[i,2]);

  for t:=1 to n do
    for i:=1 to n do
      for j:=1 to n do begin
        if (i<>t) and (i<>j) and (j<>t)
          and (ways[i,k]<>0) and (ways[k,j]<>0) then
          if ways[i,t] <= ways[t,j] then
            if ways[i,j] < ways[i,t] then
              ways[i,j]:=ways[i,t]
          else
            if ways[i,j] < ways[t,j] then
              ways[i,j]:=ways[t,j];
      end;

  for i:=1 to k do
    if ways[trun[i,1],trun[i,2]] <> 0 then
      writeln( ways[trun[i,1],trun[i,2]] )
    else
      writeln( -1);

  close(input);
  close(output);

end.





