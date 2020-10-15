function hasNumber(myString) {
    return /\d/.test(myString);
  }
  
  /**
   * @param {string[]} logs
   * @return {string[]}
   */
  var reorderLogFiles = function(logs) {
      const digitLogs = [];
      const letterLogs = [];
      
      logs.forEach(log => {
          const splittedLog = log.split(' ');
          const identifier = splittedLog[0];
          const rest = splittedLog.slice(1).join(' ');
          if (hasNumber(rest)) {
              digitLogs.push(log);
          } else {
              letterLogs.push(log)
          }
      });
      
      const compareStr = (a, b) => {
          if (a < b) {
              return -1;
          }
          return 1;
      }
      
      letterLogs.sort((a, b) => {
          const splittedA = a.split(' ');
          const targetA = splittedA.slice(1).join(' ');
          const splittedB = b.split(' ');
          const targetB = splittedB.slice(1).join(' ');
          
          return targetA < targetB ? -1 : (( targetA === targetB ) ? compareStr(splittedA[0], splittedB[0]) : 1);
      })
      
      return letterLogs.concat(digitLogs);
  };