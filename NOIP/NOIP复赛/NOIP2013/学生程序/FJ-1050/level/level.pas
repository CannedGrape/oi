var n,m,i,j,k,p,ans,least,most:longint;
    s:array[1..1005,0..1005]of longint;
    bo:array[1..1005]of boolean;
    c:array[1..1005]of boolean;
    ccc:boolean;
function pd(a,b:longint):boolean;
  var i,j:longint;
      bo:boolean;
  begin
    for i:=1 to s[a,s[a,0]] do
     begin
     bo:=false;
     for j:=1 to s[b,s[b,0]] do
       if s[a,i]=s[b,j] then bo:=true;
     if (s[a,i]>s[b,1])and(s[a,i]<s[b,s[b,0]])and(bo=false) then exit(false);
     end;
    for i:=1 to s[b,s[b,0]] do
     begin
     bo:=false;
     for j:=1 to s[a,s[a,0]] do
       if s[b,i]=s[a,j] then bo:=true;
     if (s[b,i]>s[a,1])and(s[b,i]<s[a,s[a,0]])and(bo=false) then exit(false);
     end;

    exit(true);
  end;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);


  fillchar(bo,sizeof(bo),true);
  fillchar(c,sizeof(c),false);
  readln(n,m);
  least:=10000; most:=-10000;
  for i:=1 to m do
   begin
     read(s[i,0]);
     for k:=1 to s[i,0] do begin read(s[i,k]); c[s[i,k]]:=true; end;
     if s[i,1]<least then least:=s[i,1];
     if s[i,s[i,0]]>most then most:=s[i,s[i,0]];
   end;
  for i:=1 to m-1 do
   begin
     for j:=i+1 to m do
      begin
        if (bo[i]<>false)and(bo[j]<>false)and(pd(i,j)=true) then
        begin
         if s[i,0]<s[j,0] then bo[i]:=false else bo[j]:=false;
        end;
      end;
   end;
  ans:=0;
  for i:=1 to m do
   begin
     write(bo[i],' ');
     if bo[i]=true then inc(ans);
   end;
  ccc:=false;
  for i:=least to most do
   if (c[i]=false) then ccc:=true;
  if ccc=true then inc(ans);
  writeln(ans);

  close(input);
  close(output);
end.


