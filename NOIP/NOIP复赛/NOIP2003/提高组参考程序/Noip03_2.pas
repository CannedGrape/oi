program NOIP2003_2_Logic;
  const
    maxm=20;
    dow:array[1..7]of string=('Sunday.','Monday.','Tuesday.','Wednesday.',
    'Thursday.','Friday.','Saturday.');
  var
    i,j,k,weekday,m,n,p,p1,p2,p3,index,resolution,total1,total2:byte;
    name:array[1..maxm]of string;
    witness10,witness20:array[1..100]of byte;
    witness1,witness2:array[1..100]of string;
    name0,temp,temp0,temp1,temp2:string;
    truth,truth0:array[1..maxm]of byte;
    f1,f2:text;fn1,fn2,fileNo:string;
    flag:boolean;
  begin
    write('Input fileNo:');readln(fileNo);
    fn1:='logic.in'+fileNo;fn2:='logic.ou'+fileNo;
    assign(f1,fn1);reset(f1);assign(f2,fn2);rewrite(f2);
    readln(f1,m,n,p);
    for i:=1 to m do readln(f1,name[i]);
    total1:=0;total2:=0;
    for i:=1 to p do begin
      readln(f1,temp);
      index:=pos(': ',temp);
      temp1:=copy(temp,1,index-1);
      temp2:=copy(temp,index+2,length(temp)-index-1);
      if (temp2='I am guilty.') or (temp2='I am not guilty.') then
        for j:=1 to m do
          if name[j]=temp1 then begin
            inc(total1);
            witness10[total1]:=j;
            witness1[total1]:=temp2;
            break;
          end;
      if (pos(' is guilty.',temp2)>0) or (pos(' is not guilty.',temp2)>0) then begin
        temp0:=copy(temp2,1,pos(' is ',temp2)-1);
        flag:=false;
        for k:=1 to m do
          if temp0=name[k] then begin
            flag:=true;
            break;
          end;
        if flag then
          for j:=1 to m do
            if name[j]=temp1 then begin
              inc(total1);
              witness10[total1]:=j;
              witness1[total1]:=temp2;
              break;
            end;
      end;
      flag:=false;
      for j:=1 to 7 do
        if temp2='Today is '+ dow[j] then begin
          flag:=true;
          break;
        end;
      if flag then
        for j:=1 to m do
          if name[j]=temp1 then begin
            inc(total2);
            witness20[total2]:=j;
            witness2[total2]:=temp2;
            break;
          end;
    end;
    close(f1);
    resolution:=0;
    for i:=1 to m do begin
      if resolution>1 then break;
      fillchar(truth,sizeof(truth),0);
      for j:=1 to total1 do begin
        if witness1[j]='I am guilty.' then begin
          if i=witness10[j] then
            case truth[i] of
              0:truth[i]:=1;
              2:truth[i]:=3;
            end
          else
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=2;
              1:truth[witness10[j]]:=3;
            end;
        end;
        if witness1[j]='I am not guilty.' then begin
          if i=witness10[j] then
            case truth[i] of
              0:truth[i]:=2;
              1:truth[i]:=3;
            end
          else
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=1;
              2:truth[witness10[j]]:=3;
            end;
        end;
        if (pos(' is guilty.',witness1[j])>0) then begin
          temp:=copy(witness1[j],1,pos(' is guilty.',witness1[j])-1);
          if name[i]=temp then
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=1;
              2:truth[witness10[j]]:=3;
            end
          else
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=2;
              1:truth[witness10[j]]:=3;
            end;
        end;
        if (pos(' is not guilty.',witness1[j])>0) then begin
          temp:=copy(witness1[j],1,pos(' is not guilty.',witness1[j])-1);
          if name[i]=temp then
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=2;
              1:truth[witness10[j]]:=3;
            end
          else
            case truth[witness10[j]] of
              0:truth[witness10[j]]:=1;
              2:truth[witness10[j]]:=3;
            end;
        end;
      end;
      if total2>0 then begin
        for k:=1 to m do truth0[k]:=truth[k];
        for weekday:=1 to 7 do begin
          for k:=1 to m do truth[k]:=truth0[k];
          for j:=1 to total2 do
            if pos(dow[weekday],witness2[j])>0 then
              case truth[witness20[j]] of
                0:truth[witness20[j]]:=1;
                2:truth[witness20[j]]:=3;
              end
            else
              case truth[witness20[j]] of
                0:truth[witness20[j]]:=2;
                1:truth[witness20[j]]:=3;
              end;
          p1:=0;p2:=0;p3:=0;
          for k:=1 to m do if truth[k]=1 then inc(p1);
          for k:=1 to m do if truth[k]=2 then inc(p2);
          for k:=1 to m do if truth[k]=3 then inc(p3);
          if (p1<=m-n) and (p2<=n) and (p3=0) then begin
            name0:=name[i];
            inc(resolution);
            break;
          end;
        end;
      end;
      p1:=0;p2:=0;p3:=0;
      for k:=1 to m do if truth[k]=1 then inc(p1);
      for k:=1 to m do if truth[k]=2 then inc(p2);
      for k:=1 to m do if truth[k]=3 then inc(p3);
      if (p1<=m-n) and (p2<=n) and (p3=0) and (name0<>name[i]) then begin
        name0:=name[i];
        inc(resolution);
      end;
    end;
    if resolution=1 then writeln(f2,name0);
    if resolution=0 then writeln(f2,'Impossible');
    if resolution>1 then writeln(f2,'Cannot Determine');
    close(f2);
  end.