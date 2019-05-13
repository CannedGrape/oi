program twostack;
const
  maxn=100;

var
  a,h,f:array [0..maxn] of longint;
  s,s1,s2:array [0..2*maxn] of longint;
  n:longint;

procedure fileon;
begin
  assign(input,'twostack.in');
  assign(output,'twostack.out');
  reset(input);
  rewrite(output);
end;

procedure fileoff;
begin
  close(input);
  close(output);
end;

procedure scan;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
end;

procedure print;
var
  i:longint;
begin
  write(chr(s[1]+96));
  for i:=2 to 2*n do
    write(' ',chr(s[i]+96));
  writeln;
end;

procedure dfs(deep,now,b:longint);
var
  i,j,k:longint;
begin
  if b=n then
    begin
      print;
      fileoff;
      halt;
    end;

  for k:=1 to 4 do
    case k of
      1:
        begin
          if now<=n then
            begin
              inc(s1[0]);
              s1[s1[0]]:=a[now];
              inc(s[0]);
              s[s[0]]:=1;
              dfs(deep+1,now+1,b);
              dec(s[0]);
              dec(s1[0]);
            end;
        end;
      2:
        begin
          if s1[0]>0 then
            begin
              if s1[s1[0]]=b+1 then
                begin
                  dec(s1[0]);
                  inc(s[0]);
                  s[s[0]]:=2;
                  dfs(deep+1,now,b+1);
                  dec(s[0]);
                  inc(s1[0]);
                end;
            end;
        end;
      3:
        begin
          if now<=n then
            begin
              inc(s2[0]);
              s2[s2[0]]:=a[now];
              inc(s[0]);
              s[s[0]]:=3;
              dfs(deep+1,now+1,b);
              dec(s[0]);
              dec(s2[0]);
            end;

        end;
      4:
        begin
          if s2[0]>0 then
            begin
              if s2[s2[0]]=b+1 then
                begin
                  dec(s2[0]);
                  inc(s[0]);
                  s[s[0]]:=4;
                  dfs(deep+1,now,b+1);
                  dec(s[0]);
                  inc(s2[0]);
                end;
            end;

        end;
    end;
end;

procedure main;
var
  i,j:longint;
begin
  fillchar(s,sizeof(s),0);
  fillchar(s1,sizeof(s1),0);
  fillchar(s2,sizeof(s2),0);
  dfs(1,1,0);
  writeln(0);
end;

begin
  fileon;
  scan;
  main;
  fileoff;
end.
