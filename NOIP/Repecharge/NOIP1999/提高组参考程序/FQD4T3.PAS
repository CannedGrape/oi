program FenQuPrepare_Day4_Task3_FQ99P3;
type
  real=extended;
const
  fn_in='input.txt';
  maxn=100;
var
  ans,c,d1,d2:real;
  can:boolean;
  n:Integer;
  d:array[0..maxn] of real;
  p:array[0..maxn] of real;

  procedure init;
  var s:string;
      i:Integer;
  begin
    assign(input,fn_in);
    reset(input);
    readln(d1,c,d2,p[0],n);
    for i:=1 to n do readln(d[i],p[i]);
  end;

  procedure main;
  var cur,i,j:Integer;
      rest,min:real;
  begin
    can:=true;
    for i:=1 to n do
      if (d[i]-d[i-1])>c*d2 then can:=false;
    if d1-d[n]>c*d2 then can:=false;
    if not can then exit;
    rest:=0;
    ans:=0;
    for cur:=0 to n do
    begin
      min:=1e10;
      i:=cur;
      while (i<=n) and ((d[i]-d[cur])<=c*d2) do
      begin
        if p[i]<min then
        begin
          min:=p[i];
          j:=i;
        end;
        inc(i);
      end;
      if j=cur then
      begin
        if c*d2>(d1-d[cur]) then
        begin
          if rest*d2<d1-d[cur] then
          begin
            ans:=ans+p[cur]*((d1-d[cur])/d2-rest);
            rest:=(d1-d[cur])/d2;
          end;
        end else
        begin
          ans:=ans+p[cur]*(c-rest);
          rest:=c;
        end
      end else
      begin
        if rest*d2<d[j]-d[cur] then
        begin
          ans:=ans+p[cur]*((d[j]-d[cur])/d2-rest);
          rest:=(d[j]-d[cur])/d2;
        end;
      end;
      rest:=rest-(d[cur+1]-d[cur])/d2;
    end;
  end;

  procedure out;
  begin
    if can then
    begin
      ans:=round(ans*100)/100;
      writeln(ans:0:2);
    end else writeln('No solution');
  end;

  begin
    init;
    main;
    out;
  end.