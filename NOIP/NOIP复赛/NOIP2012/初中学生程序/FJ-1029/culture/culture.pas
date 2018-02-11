program culture;
  var
    map,no:array[1..100,1..100]of integer;
    cul,learn,yes:array[0..100]of integer;
    n,k,m,s,t,a,b,c,l,i,j:integer;
    ans,x:int64;


  procedure dfs(city:longint);
    var
      i,j,o:longint;
    begin
      if city=t
        then
          begin
            ans:=x;
            l:=1;
          end
        else
          begin
            for i:=1 to n do
              if (map[city,i]<>0) and (learn[cul[i]]=0) and (x+map[city,i]<ans) and (yes[i]=0)
                then
                  begin
                    o:=0;
                    for j:=1 to k do
                      if (no[cul[i],j]=1) and (learn[j]=1)
                        then o:=1;
                    if o=0
                      then
                        begin
                          learn[cul[i]]:=1;
                          yes[i]:=1;
                          x:=x+map[city,i];
                          dfs(i);
                          x:=x-map[city,i];
                          yes[i]:=0;
                          learn[cul[i]]:=0;
                        end;
                  end;
          end;
    end;

begin
  assign(input,'culture.in');
  assign(output,'culture.out');
  reset(input);
  rewrite(output);
  readln(n,k,m,s,t);
  for i:=1 to n do
    read(cul[i]);
  for i:=1 to k do
    begin
      for j:=1 to k do
        read(no[i,j]);
    end;
  for i:=1 to m do
    begin
      read(a,b,c);
      if (map[a,b]=0) or (c<map[a,b])
        then
          begin
            map[a,b]:=c;
            map[b,a]:=c;
          end;
    end;
  l:=0;
  yes[s]:=1;
  learn[cul[s]]:=1;
  ans:=maxlongint;
  dfs(s);
  if l=0
    then write('-1')
    else write(ans);
  close(input);
  close(output);
end.
