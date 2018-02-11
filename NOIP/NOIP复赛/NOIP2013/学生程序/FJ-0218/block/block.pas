Program blk;
var
Min:array[1..400012]of longint;
Max:array[1..400012]of longint;
Dec:array[1..400012]of longint;
data:array[1..1000002] of longint;
ans:longint; blks,b:longint;
function getmax(a,b:longint):longint;
begin if a>b then exit(a) else exit(b); end;
function getmin(a,b:longint):longint;
begin if a<b then exit(a) else exit(b); end;

procedure update(pl:longint);
begin Min[pl]:=getmin(Min[pl*2],Min[pl*2+1]); 
Max[pl]:=getmax(Max[pl*2],Max[pl*2+1]);
end;
procedure build(fr,ed,pl:longint) ;
var t:longint;
begin
if fr=ed then begin Max[pl] := data[fr];
Min[pl]:=data[fr]; exit ; end;
t:=(fr+ed)div 2;
build(fr,t,pl*2);
build(t+1,ed,pl*2+1);
update(pl); end;

procedure change(pl,fr,ed:longint;add:boolean) ;
var opt,o1,o2:boolean; minval,i:longint; mid:longint;
begin
//writeln('doing',fr,ed);
if (Max[pl] = 0) then exit; 
if (Dec[pl] > 0) then begin 
Min[pl]:=Min[pl] - Dec[pl];
Max[pl]:=Max[pl] - Dec[pl];
Dec[pl] :=0;
if (Max[pl] = 0) then exit; 
end;

if ((Min[pl] = 0) and (fr <> ed))
    then begin
    o1:=false;
    o2:=false;
    mid :=(fr+ed)div 2;
    if ((data[mid] - minval = 0) and (data[mid+1] - minval > 0)) then begin o1:=true;o2:=true; end;
    if ((data[mid] - minval > 0) and (data[mid+1] - minval = 0)) then begin o1:=true;o2:=true; end;
    if ((data[mid] - minval > 0) and (data[mid+1] - minval > 0)) then begin o1:=true;o2:=false; end;    
    if ((data[mid] - minval = 0) and (data[mid+1] - minval = 0)) then begin o1:=true;o2:=true; end;
    if ((ed = mid+1) and (ed <> blks)) then o2:=false;
    if ((fr = mid) and (fr <> 1)) then o1:=false;
    change(pl*2,fr,mid,o1);
    change(pl*2+1,mid+1,ed,o2);
    update(pl); end
    else begin
    Max[pl] := Max[pl] - Min[pl];
    inc(Dec[pl*2],Min[pl]);
    inc(Dec[pl*2+1],Min[pl]);
    minval:= Min[pl];
    Min[pl] := 0;
    //假设左边已经空掉了，那么..就不该连成一块，于是都是true
    //第一题我搞了好久。。。
    if (add) then begin
    inc (ans);
//writeln('adding at',fr,ed);
    end;
    o1:=false;
    o2:=false;
    mid :=(fr+ed)div 2;
    if ((data[mid] - minval = 0) and (data[mid+1] - minval > 0)) then begin o1:=true;o2:=true; end;
    if ((data[mid] - minval > 0) and (data[mid+1] - minval = 0)) then begin o1:=true;o2:=true; end;
    if ((data[mid] - minval > 0) and (data[mid+1] - minval > 0)) then begin o1:=true;o2:=false; end;    
    if ((data[mid] - minval = 0) and (data[mid+1] - minval = 0)) then begin o1:=true;o2:=true; end;
    //one side
    change(pl*2,fr,mid,o1);
    change(pl*2+1,mid+1,ed,o2);    
    update(pl);
    end;

end;

BEGIN
   assign(input,'block.in');
   assign(output,'block.out');
   reset(input);
   rewrite(output);
read(blks);
for b:=1 to blks do read(data[b]);
build(1,blks,1);
while (Max[1] > 0) do change(1,1,blks,true);
writeln(ans);
   close(input);
   close(output);

END.




