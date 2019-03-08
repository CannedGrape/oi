var a:Array[1..100000] of longint;
    f,ans:array[1..100000,1..2] of longint;
    n,i,j,k,temp:longint;

function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  f[1,1]:=1;ans[1,1]:=a[1];ans[1,2]:=a[1]; temp:=0;
  for k:=1 to 2 do begin
  for i:=2 to n do
    begin
      if a[i]<ans[i-1,1] then
        begin
          if f[i-1,1]+1>f[i-1,2] then
            begin
              f[i,2]:=f[i-1,1]+1;
              ans[i,2]:=a[i];
            end else
            begin
              f[i,2]:=f[i-1,2];
              if a[i]<ans[i-1,2] then ans[i,2]:=a[i] else ans[i,2]:=ans[i-1,2];
            end;
        end else
          begin
            f[i,2]:=f[i-1,2];
              if a[i]<ans[i-1,2] then ans[i,2]:=a[i] else ans[i,2]:=ans[i-1,2];
          end;
      if a[i]>ans[i-1,2] then
        begin
          if f[i-1,2]+1>f[i-1,1] then
            begin
              f[i,1]:=f[i-1,2]+1;
              ans[i,1]:=a[i];
            end else
            begin
              f[i,1]:=f[i-1,1];
              if a[i]>ans[i-1,1] then ans[i,1]:=a[i] else ans[i,1]:=ans[i-1,1];
            end;
        end else
        begin
           f[i,1]:=f[i-1,1];
              if a[i]>ans[i-1,1] then ans[i,1]:=a[i] else ans[i,1]:=ans[i-1,1];
        end;
    end;
    if max(f[n,1],f[n,2])>temp then temp:=max(f[n,1],f[n,2]);
    fillchar(ans,sizeof(ans),0);fillchar(f,sizeof(f),0);
    f[1,2]:=1;ans[1,1]:=a[1];ans[1,2]:=a[1];
  end;
  writeln(temp);
    close(input);close(output);
end.