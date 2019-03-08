{$r-,q-,s-,n+,g+}
program FenQuPrepare_Day5_Task3_FQ2000P3;
const
  fn_in='input.txt';
  maxn=20;
var
  ans,n:Integer;
  words:array[1..maxn] of string;
  head:char;
  g:array[1..maxn,1..maxn] of integer;
  mk:array[1..maxn] of integer;

  procedure init;
  var i:Integer;
  begin
    assign(input,fn_in);
    reset(input);
    readln(n);
    for i:=1 to n do
      readln(words[i]);
    readln(head);
  end;

  procedure MakeGraph;
  var l,i,j,k:Integer;
  begin
    for i:=1 to n do
     for j:=1 to n do
     begin
       g[i,j]:=0;
       for k:=length(words[i]) downto 2 do
         if k+length(words[j])-1>length(words[i]) then
         begin
           l:=pos(copy(words[i],k,length(words[i])-k+1),words[j]);
           if l=1 then
           begin
             g[i,j]:=k+length(words[j])-1-length(words[i]);
             break;
           end;
         end;
     end;
  end;

  procedure dfs(u,len:integer);
  var i:Integer;
  begin
    if len>ans then ans:=len;
    for i:=1 to n do
      if (mk[i]>0) and (g[u,i]>0) then
      begin
        dec(mk[i]);
        dfs(i,len+g[u,i]);
        inc(mk[i]);
      end;
  end;

  procedure main;
  var i:Integer;
  begin
    MakeGraph;
    ans:=0;
    for i:=1 to n do mk[i]:=2;
    for i:=1 to n do
      if words[i][1]=head then
      begin
        dec(mk[i]);
        dfs(i,length(words[i]));
        inc(mk[i]);
      end;
  end;

  procedure out;
  begin
    writeln(ans);
  end;

  begin
    init;
    main;
    out;
  end.