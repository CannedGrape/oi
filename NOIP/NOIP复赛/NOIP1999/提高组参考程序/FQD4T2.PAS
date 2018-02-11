program FenQuPrepare_Day4_Task2_FQ99P2;
const
  fn_in='input.txt';
  maxlen=100;
  stri='0123456789ABCDEF';
var
  a,b:array[1..maxlen] of integer;
  len,n,step:integer;

  procedure init;
  var s:string;
      i:Integer;
  begin
    assign(input,fn_in);
    reset(input);
    readln(n);
    readln(s);
    len:=length(s);
    for i:=1 to len do a[i]:=pos(s[i],stri)-1;
  end;

  function IsParlin:boolean;
  var i:integer;
  begin
    for i:=1 to len do
      if a[i]<>a[len+1-i] then begin IsParlin:=false;exit end;
    IsParlin:=true;
  end;

  procedure main;
  var i,j:Integer;
  begin
    step:=0;
    while(step<=30) and (not IsParlin) do
    begin
      inc(step);
      for i:=1 to len do b[len+1-i]:=a[i];
      for i:=1 to len do
      begin
        inc(a[i],b[i]);
        if a[i]>=n then
        begin
          inc(a[i+1]);
          dec(a[i],n);
        end;
      end;
      if a[len+1]>0 then inc(len);
    end;
  end;

  procedure out;
  begin
    if step>30 then writeln('Impossible')
               else writeln('STEP=',step);
  end;

  begin
    init;
    main;
    out;
  end.