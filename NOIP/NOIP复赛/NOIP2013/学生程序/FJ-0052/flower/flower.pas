program flower;
var
  a:array[0..100100]of longint;
  u,bo:boolean;
  n,ans,lp,lt,i:longint;
  dui:array[0..100100]of longint;
  tot,l,zhizhen:longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;

function qizen:longint;
begin
  zhizhen:=1;
  while zhizhen<n do
  begin
    if bo=false then
      begin
        if u then
          begin
            dui[1]:=a[zhizhen];
            l:=1;
          end;
        u:=false;

        inc(zhizhen);
          begin
            if a[zhizhen]>=dui[l] then
              begin
                inc(l);
                dui[l]:=a[zhizhen];
              end
            else
              begin
                bo:=true;
                inc(tot);
              end;
          end;
      end;
    if bo then
      begin

        if u=false then
          begin
            dui[1]:=a[zhizhen];
            l:=1;
          end;
        u:=true;
        inc(zhizhen);

          begin
            if a[zhizhen]<=dui[l] then
              begin
                inc(l);
                dui[l]:=a[zhizhen];
              end
            else
              begin
                bo:=false;
                inc(tot);
              end;
          end;
      end;
  end;
  inc(tot);
  exit(tot);
end;


function qijian:longint;
begin
  zhizhen:=1;tot:=0;
  while zhizhen<n do
  begin
    if bo then
      begin
        if u then
          begin
            dui[1]:=a[zhizhen];
            l:=1;
          end;
        u:=false;
        inc(zhizhen);
          begin
            if a[zhizhen]>=dui[l] then
              begin
                inc(l);
                dui[l]:=a[zhizhen];
              end
            else
              begin
                bo:=false;
                inc(tot);
              end;
          end;
      end;
    if bo=false then
      begin
        if u=false then
          begin
            dui[1]:=a[zhizhen];
            l:=1;
          end;
        u:=true;
        inc(zhizhen);
          begin
            if a[zhizhen]<=dui[l] then
              begin
                inc(l);
                dui[l]:=a[zhizhen];
              end
            else
              begin
                bo:=true;
                inc(tot);
              end;
          end;
      end;
  end;
  inc(tot);
  exit(tot);
end;


begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  bo:=false;
  u:=true;
  tot:=0;
  fillchar(dui,sizeof(dui),0);
  lp:=qizen;
  bo:=false;
  u:=false;
  tot:=0;
  fillchar(dui,sizeof(dui),0);
  lt:=qijian;
  //writeln(lp,' ',lt);
  ans:=max(lp,lt);
  writeln(ans);
  close(input);
  close(output);
end.
