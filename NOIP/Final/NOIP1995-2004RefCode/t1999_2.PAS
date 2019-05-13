program p99_2(input,output);{Hui Wen Shu}
var find:boolean;
    s,t:string;
    n,step:integer;

function huiwen(s:string):boolean;
var flag:boolean;i:integer;
begin
    flag:=true;i:=1;
    while flag and (i<=length(s) div 2 ) do begin
       if s[i]<>s[length(s)-i+1] then flag:=false;
       i:=i+1;end;
    huiwen:=flag;
end;

function tran(s:string):string;
var t:string;i:integer;
begin
    t[0]:=s[0];
    for i:=1 to length(s) do
        t[i]:=s[length(s)+1-i];
    tran:=t;
end;

function add(s,t:string;n:integer):string;
var i,vs,vt:integer;c:0..1;
begin
     c:=0;
     for i:=1 to length(s) do begin
        if n<=10 then begin
              vs:=ord(s[i])-ord('0');
              vt:=ord(t[i])-ord('0');
              vt:=vs+vt+c;
              if vt>=n then begin c:=vt div n;vt:=vt mod n;end
                 else c:=0;
              t[i]:=chr(vt+ord('0'));
           end
        else if n=16 then begin
              if (s[i]>='0') and (s[i]<='9') then
                        vs:=ord(s[i])-ord('0')
                 else if (s[i]>='A') and (s[i]<='F') then
                       vs:=ord(s[i])-ord('A')+10
                    else begin writeln('ERROR 1') end;
              if (t[i]>='0') and (t[i]<='9') then
                      vt:=ord(t[i])-ord('0')
                 else if (t[i]>='A') and (t[i]<='F') then
                      vt:=ord(t[i])-ord('A')+10
                   else begin writeln('ERROR t') end;
              vt:=vs+vt+c;
              if vt>15 then begin
                      c:=vt div n;vt:=vt mod n;end
                  else c:=0;
              if vt<10 then begin t[i]:=chr(vt+ord('0'));end
                 else begin t[i]:=chr(vt-10+ord('A'));end;
           end
        else begin writeln;writeln('Error N(JinZhi CuoWu),exit!!');halt;end;
     end;
     if c>0 then begin t[length(t)+1]:=chr(c+ord('0'));t[0]:=chr(ord(t[0])+1);end;
     add:=t;
end;

begin
    assign(input,'huiwen.in');
    reset(input);
    readln(n);readln(s);
    close(input);
    step:=0;find:=false;
    while not find and (step<30) do
     begin
         step:=step+1;
         t:=tran(s);   
         s:=add(s,t,n);  
         if huiwen(s) then find:=true;
     end;
     assign(output,'huiwen.out');
     rewrite(output);
    if find then writeln('STEP=',step)
      else writeln('Impossible!');
    close(output);
end.