/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      // Timer to reject after t ms
      const timer = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);

      // Execute original function
      fn(...args)
        .then((res) => {
          clearTimeout(timer); // cancel timeout
          resolve(res);
        })
        .catch((err) => {
          clearTimeout(timer); // cancel timeout
          reject(err);
        });
    });
  };
};