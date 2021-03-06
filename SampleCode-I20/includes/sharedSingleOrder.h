#ifndef SHARED_SINGLE_ORDER_H
#define SHARED_SINGLE_ORDER_H
#include <apiDataTypes.h>
#include <sgSymbolDataDefines.h>
#include <sharedCommands.h>
#include <sharedResponse.h>
#include <boost/shared_ptr.hpp>
#include <cmdDefines.h>
#include <money.h>
extern "C"
{
  namespace API2
  {

    class SingleOrderImpl;
    class SpreadContractImpl;

    /**
     * @brief The SingleOrder class. This wrapper is used for sending Single Leg Orders.
     * Usage: Create an object for This using API2::SGContext::createNewOrder
     */
    class SingleOrder
    {

      protected:

        //    SingleOrderImpl *pimpl;

        /**
         * @brief _clOrdId
         */
        DATA_TYPES::CLORDER_ID _clOrdId;

        /**
         * @brief _origClientOrderId
         */
        DATA_TYPES::CLORDER_ID _origClientOrderId;

        /**
         * @brief _symbolId
         */
        DATA_TYPES::SYMBOL_ID _symbolId;  // From symbolId, exchange will infer which exchange

        /**
         * @brief _clientId
         */
        DATA_TYPES::CLIENT_ID _clientId;

        /**
         * @brief _quantity
         */
        DATA_TYPES::QTY _quantity;

        /**
         * @brief _disclosedQuantity
         */
        DATA_TYPES::QTY _disclosedQuantity;

        /**
         * @brief _filledQuantity
         */
        DATA_TYPES::QTY _filledQuantity;

        /**
         * @brief _oldQuantity
         */
        DATA_TYPES::QTY _oldQuantity;

        /**
         * @brief _price
         */
        DATA_TYPES::PRICE _price;

        /**
         * @brief _stopPrice
         */
        DATA_TYPES::PRICE _stopPrice;

        /**
         * @brief _optionStrikePrice
         */
        DATA_TYPES::PRICE _optionStrikePrice;

        /**
         * @brief _expiryDate
         */
        DATA_TYPES::EXPIRY_DATE _expiryDate;


        /**
         * @brief _exchangeEntryTime
         */
        DATA_TYPES::EXCHANGE_TIME _exchangeEntryTime;

        /**
         * @brief _exchangeModifyTime
         */
        DATA_TYPES::EXCHANGE_TIME  _exchangeModifyTime;

        /**
         * @brief _transactionType
         */
        DATA_TYPES::ENUM _transactionType;

        /**
         * @brief _orderMode
         */
        DATA_TYPES::ENUM _orderMode;

        /**
         * @brief _securityType
         */
        DATA_TYPES::ENUM _securityType;

        /**
         * @brief _optionMode
         */
        DATA_TYPES::ENUM _optionMode;

        /**
         * @brief _optionAttribute
         */
        DATA_TYPES::ENUM _optionAttribute;

        /**
         * @brief _orderValidity
         */
        DATA_TYPES::ENUM _orderValidity;

        /**
         * @brief _gtdDate
         */
        DATA_TYPES::GTD_Date _gtdDate; 
        /**
         * @brief _productType
         */
        DATA_TYPES::ENUM _productType;

        /**
         * @brief _orderType
         */
        DATA_TYPES::ENUM _orderType;

        /**
         * @brief _instrumentType
         */
        DATA_TYPES::ENUM _instrumentType;

        /**
         * @brief _settlementPeriod
         */
        DATA_TYPES::SETTLEMENT_PERIOD _settlementPeriod; // Default 10 days

        /**
         * @brief _orderStatus
         */
        DATA_TYPES::ENUM _orderStatus; // Needed for OMS

        //    /**
        //     * @brief _traderId
        //     */
        //    DATA_TYPES::TRADER_ID _traderId;

        /**
         * @brief _symbol
         */
        char  _symbol[SYMBOL_SIZE];

        /**
         * @brief _series
         */
        char  _series[SERIES_SIZE];

        /**
         * @brief _exchangeOrderId
         */
        char  _exchangeOrderId[EXCHANGE_ORDERID_SIZE];

        /**
         * @brief _tokenId
         */
        UNSIGNED_INTEGER _tokenId;

#ifdef CTP_ORDER_CONTIGENCY_SUPPORT_ENABLED
        CREATE_FIELD(UNSIGNED_CHARACTER, OrderContigencyFlag);
#endif

        AccountDetail _AccountDetails;

        //    CREATE_FIELD(API2::AccountDetail, AccountDetails);
        //    boost::shared_ptr<AccountDetail> _AccountDetails;
        /**
         * @brief _orderCategory
         */
        DATA_TYPES::ENUM _orderCategory;

        /**
         * @brief strategy type mainly for MCX
         */

        short _strategyType;


#ifdef MULTI_CURRENCY_SUPPORT
        CREATE_FIELD( Currency::Money, PriceCurrency);
#endif
        CREATE_FIELD(short, SelfTradeCancelFlag);

        /*
         * @brief : load balancing id, kind of a strategy id which is to be used in load balancing
         * */
        DATA_TYPES::STRATEGY_ID _loadBalancingId;

        /*
         * @brief : DealerId field, it is a client id will be used in DMA
         * */
        DATA_TYPES::CLIENT_ID _dealerId;

      public :

        //    SingleOrderImpl *getImpl()const{return pimpl;}
        //    void setImpl(SingleOrderImpl *impl) {pimpl = impl;}

        SingleOrder(const SingleOrder& other);
        SingleOrder& operator =(const SingleOrder& );

        SingleOrder *clone();


        /**
         * @brief dump
         */
        virtual void dump() const ;

        virtual ~SingleOrder();

        /**
         * @brief ApiSingleOrder
         */
        SingleOrder();

        /**
         * @brief initialize
         */
        void initialize();

        /**
         * @brief ApiSingleOrder
         * @param symbolId
         * @param staticData
         * @param clientId
         * @param quantity
         * @param disclosedQuantity
         * @param price
         * @param stopPrice
         * @param type
         * @param product
         * @param mode
         * @param validity
         * @param traderId
         */
        SingleOrder(DATA_TYPES::SYMBOL_ID symbolId,
            const SymbolStaticData& staticData,
            DATA_TYPES::CLIENT_ID clientId,
            DATA_TYPES::QTY quantity,
            DATA_TYPES::QTY disclosedQuantity,
            DATA_TYPES::PRICE price,
            DATA_TYPES::PRICE stopPrice,
            DATA_TYPES::OrderType type, // Limit, Market, Stop, Stop Limit
            DATA_TYPES::ProductType product, // Intraday, Delivery
            DATA_TYPES::OrderMode mode, // Buy, Sell
            DATA_TYPES::OrderValidity validity, // GTD, FOK etc.
            DATA_TYPES::TRADER_ID traderId,
            const AccountDetail &accountDetails=AccountDetail());

        SingleOrder(const DATA_TYPES::SYMBOL_ID &symbolId,
            const std::string &symbol,
            const std::string &series,
            const DATA_TYPES::EXPIRY_DATE &expiryDate,
            const DATA_TYPES::SecurityType &securityType,
            const DATA_TYPES::InstrumentType &instrumentType,
            DATA_TYPES::TransactionType transactionType);

        /**
         * @brief initialize
         * @param symbolId
         * @param staticData
         * @param clientId
         * @param quantity
         * @param disclosedQuantity
         * @param price
         * @param stopPrice
         * @param type
         * @param product
         * @param mode
         * @param validity
         * @param traderId
         * @return
         */
        int  initialize(DATA_TYPES::SYMBOL_ID symbolId,
            const SymbolStaticData& staticData,
            DATA_TYPES::CLIENT_ID clientId,
            DATA_TYPES::QTY quantity,
            DATA_TYPES::QTY disclosedQuantity,
            DATA_TYPES::PRICE price,
            DATA_TYPES::PRICE stopPrice,
            DATA_TYPES::OrderType type, // Limit, Market, Stop, Stop Limit
            DATA_TYPES::ProductType product, // Intraday, Delivery
            DATA_TYPES::OrderMode mode, // Buy, Sell
            DATA_TYPES::OrderValidity validity, // GTD, FOK etc.
            DATA_TYPES::TRADER_ID traderId,
            const AccountDetail &accountDetails= AccountDetail());

        /**
         * @brief getExchangeSecurityId
         * @return ExchangeSecurityId
         */
        SIGNED_LONG getExchangeSecurityId() const ;

        /**
         * @brief getExchangeId returns Exchange ID
         * @return API2::DATA_TYPES::ExchangeId
         */
        DATA_TYPES::ExchangeId getExchangeId() const;

        /**
         * @brief getClOrdId To get the unique Client Order Id (unique to the system)
         * @return API2::DATA_TYPES::CLORDER_ID
         */
        DATA_TYPES::CLORDER_ID getClOrdId() const ;

        /**
         * @brief getOrigClientOrderId  If the order is modified, it returns the Parent Order's ClientOrderId
         * @return API2::DATA_TYPES::CLORDER_ID
         */
        DATA_TYPES::CLORDER_ID getOrigClientOrderId() const ;

        /**
         * @brief getExchangeOrderId It returns Exchange's Order Id
         * @return const char pointer to ExchangeOrderId
         */
        const char* getExchangeOrderId() const ;

        /**
         * @brief getSymbolId To get SymbolId
         * @return
         */
        DATA_TYPES::SYMBOL_ID getSymbolId() const ;

        /**
         * @brief getClientId
         * @return API2::DATA_TYPES::CLIENT_ID
         */
        DATA_TYPES::CLIENT_ID getClientId() const ;

        /**
         * @brief getQuantity To get Order quantity
         * @return API2::DATA_TYPES::QTY
         */
        DATA_TYPES::QTY getQuantity() const ;

        /**
         * @brief getDisclosedQuantity To get Disclosed Order Qty
         * @return API2::DATA_TYPES::QTY
         */
        DATA_TYPES::QTY getDisclosedQuantity() const ;

        /**
         * @brief getFilledQuantity To get Filled Quantity
         * @return API2::DATA_TYPES::QTY
         */
        DATA_TYPES::QTY getFilledQuantity() const ;

        /**
         * @brief getOldQuantity
         * @return
         */
        DATA_TYPES::QTY getOldQuantity() const ;

        /**
         * @brief getPrice To get the Limit price provided for order
         * @return API2::DATA_TYPES::PRICE
         */
        DATA_TYPES::PRICE getPrice() const ;

        /**
         * @brief getStopPrice To get the stop Price provided for Order
         * @return API2::DATA_TYPES::PRICE
         */
        DATA_TYPES::PRICE getStopPrice() const ;

        /**
         * @brief getExchangeEntryTime To get the Time for Order entry at Exchange
         * @return API2::DATA_TYPES::EXCHANGE_TIME (epoch_time)
         */
        DATA_TYPES::EXCHANGE_TIME getExchangeEntryTime() const ;

        /**
         * @brief getExchangeModifyTime To get the Time for Order modification at Exchange
         * @return API2::DATA_TYPES::EXCHANGE_TIME
         */
        DATA_TYPES::EXCHANGE_TIME getExchangeModifyTime() const ;

        /**
         * @brief getTransactionType To get thr transaction type for the Order
         * tbd
         * @return The API2::DATA_TYPES::Transaction_TYPE
         */
        DATA_TYPES::TransactionType getTransactionType() const ;

        /**
         * @brief getOrderMode To get the Order Mode
         * @return
         */
        DATA_TYPES::OrderMode getOrderMode() const ;

        /**
         * @brief getSecurityType
         * @return
         */
        DATA_TYPES::SecurityType getSecurityType() const ;

        /**
         * @brief getOptionMode
         * @return
         */
        DATA_TYPES::OptionMode getOptionMode() const ;

        /**
         * @brief getOptionStrikePrice
         * @return
         */
        DATA_TYPES::PRICE getOptionStrikePrice() const;

        /**
         * @brief getExpiryDate
         * @return
         */
        DATA_TYPES::EXPIRY_DATE  getExpiryDate() const;

        /**
         * @brief getOptionAttribute
         * @return
         */
        DATA_TYPES::OptionAttribute getOptionAttribute() const ;

        /**
         * @brief getOrderValidity
         * @return
         */
        DATA_TYPES::OrderValidity getOrderValidity() const ;

        /**
         * @brief getGTDDate
         * @return
         */
        DATA_TYPES::GTD_Date getGTDDate() const;

        /**
         * @brief getProductType
         * @return
         */
        DATA_TYPES::ProductType getProductType() const ;

        /**
         * @brief getOrderType
         * @return
         */
        DATA_TYPES::OrderType getOrderType() const ;

        /**
         * @brief getInstrumentType
         * @return
         */
        DATA_TYPES::InstrumentType getInstrumentType() const ;

        /**
         * @brief getSettlementPeriod
         * @return
         */
        DATA_TYPES::SETTLEMENT_PERIOD getSettlementPeriod() const;

        /**
         * @brief getOrderStatus
         * @return
         */
        DATA_TYPES::OrderStatus getOrderStatus() const;

        /**
         * @brief getSymbol
         * @return
         */
        const char* getSymbol() const;

        /**
         * @brief getSeries
         * @return
         */
        const char* getSeries() const;

        /**
         * @brief getTokenId
         * @return
         */
        UNSIGNED_INTEGER getTokenId() const;
        // Required for BSE

        /**
         * @brief getDeltaQty
         * @return
         */
        int getDeltaQty() const;

        /**
         * @brief getTraderId
         * @return
         */
        DATA_TYPES::TRADER_ID getTraderId() const;
        
        /**
         * @brief setClOrdId
         * @param clOrdId
         */
        /**
         * @brief getStrategyType
         * @return
         */
        short  getStrategyType() const;

        /**
         * @brief getLoadBalancingId
         * @return
         */
        DATA_TYPES::STRATEGY_ID getLoadBalancingId() const;

        /*
         * @brief getDealerId
         * @return
         * */
        DATA_TYPES::CLIENT_ID getDealerId() const;

        /**
         * @brief setStrategyType
         * @return
         */
        void   setStrategyType( short );


        void setClOrdId(DATA_TYPES::CLORDER_ID clOrdId);

        /**
         * @brief setOrigClientOrderId
         * @param origClientOrderId
         */
        void setOrigClientOrderId(DATA_TYPES::CLORDER_ID origClientOrderId) ;

        /**
         * @brief setExchangeOrderId
         * @param exchangeOrderId
         */
        void setExchangeOrderId(char exchangeOrderId[]);

        /**
         * @brief setExchangeOrderId
         * @param exchangeOrderId
         */
        void setExchangeOrderId(const char *exchangeOrderId);

        /**
         * @brief setExchangeOrderId
         * @param exchangeOrderId
         */
        void setExchangeOrderId(const std::string& exchangeOrderId);

        /**
         * @brief setSymbolId
         * @param symbolId
         */
        void setSymbolId(DATA_TYPES::SYMBOL_ID symbolId);

        /**
         * @brief setClientId
         * @param clientId
         */
        void setClientId(DATA_TYPES::CLIENT_ID clientId);

        /**
         * @brief setQuantity
         * @param quantity
         */
        void setQuantity(DATA_TYPES::QTY quantity) ;

        /**
         * @brief setDisclosedQuantity
         * @param disclosedQuantity
         */
        void setDisclosedQuantity(DATA_TYPES::QTY disclosedQuantity);

        /**
         * @brief setFilledQuantity
         * @param filledQuantity
         */
        void setFilledQuantity(DATA_TYPES::QTY filledQuantity);

        /**
         * @brief setOldQuantity
         * @param oldQuantity
         */
        void setOldQuantity(DATA_TYPES::QTY oldQuantity) ;

        /**
         * @brief setPrice
         * @param price
         */
        void setPrice(DATA_TYPES::PRICE price);

        /**
         * @brief setStopPrice
         * @param stopPrice
         */
        void setStopPrice(DATA_TYPES::PRICE stopPrice) ;

        /**
         * @brief setOptionStrikePrice
         * @param strikePrice
         */
        void setOptionStrikePrice(DATA_TYPES::PRICE strikePrice) ;

        /**
         * @brief setExpiryDate
         * @param expiryDate
         */
        void setExpiryDate(DATA_TYPES::EXPIRY_DATE expiryDate);

        /**
         * @brief setExchangeEntryTime
         * @param exchangeEntryTime
         */
        void setExchangeEntryTime(DATA_TYPES::EXCHANGE_TIME exchangeEntryTime) ;

        /**
         * @brief setExchangeModifyTime
         * @param exchangeModifyTime
         */
        void setExchangeModifyTime(DATA_TYPES::EXCHANGE_TIME exchangeModifyTime) ;

        /**
         * @brief setTransactionType
         * @param transactionType
         */
        void setTransactionType(DATA_TYPES::TransactionType transactionType);

        /**
         * @brief setOrderMode
         * @param orderMode
         */
        void setOrderMode(DATA_TYPES::OrderMode orderMode) ;

        /**
         * @brief setSecurityType
         * @param securityType
         */
        void setSecurityType(DATA_TYPES::SecurityType securityType) ;

        /**
         * @brief setOptionMode
         * @param optionMode
         */
        void setOptionMode(DATA_TYPES::OptionMode optionMode) ;

        /**
         * @brief setOptionAttribute
         * @param optionAttribute
         */
        void setOptionAttribute(DATA_TYPES::OptionAttribute optionAttribute) ;

        /**
         * @brief setOrderValidity
         * @param orderValidity
         */
        void setOrderValidity(DATA_TYPES::OrderValidity orderValidity) ;

        /**
         * @brief setGTDDate
         * @param gtdDate
         */
        void setGTDDate(DATA_TYPES::GTD_Date gtdDate);

        /**
         * @brief setProductType
         * @param productType
         */
        void setProductType(DATA_TYPES::ProductType productType) ;

        /**
         * @brief setOrderType
         * @param orderType
         */
        void setOrderType(DATA_TYPES::OrderType orderType) ;

        /**
         * @brief setInstrumentType
         * @param instrumentType
         */
        void setInstrumentType(DATA_TYPES::InstrumentType instrumentType) ;

        /**
         * @brief setSettlementPeriod
         * @param settlementPeriod
         */
        void setSettlementPeriod(DATA_TYPES::SETTLEMENT_PERIOD settlementPeriod) ;

        /**
         * @brief setOrderStatus
         * @param orderStatus
         */
        void setOrderStatus(DATA_TYPES::OrderStatus orderStatus) ;

        /**
         * @brief setSymbol
         * @param symbol
         */
        void setSymbol(const char *symbol ) ;

        /**
         * @brief setSeries
         * @param series
         */
        void setSeries(const char *series) ;

        /**
         * @brief setTraderId
         * @param traderId
         */
        void setTraderId(DATA_TYPES::TRADER_ID traderId);

        /**
         * @brief setTokenId
         * @param val
         */
        void setTokenId(UNSIGNED_INTEGER val) ;

        /**
         * @brief setOrderCategory
         * @param orderCategory
         */
        void setOrderCategory(DATA_TYPES::ENUM orderCategory);

        /**
         * @brief getAccountDetails
         * @return
         */
        AccountDetail getAccountDetails() const;

        /**
         * @brief getRefAccountDetails
         * @return
         */
        AccountDetail &getRefAccountDetails();

        /**
         * @brief setAccountDetails
         * @param detail
         */
        void setAccountDetails(const AccountDetail& detail);

        /**
         * @brief setLoadBalancingId
         * @param detail
         */
        void setLoadBalancingId(DATA_TYPES::STRATEGY_ID loadBalancingId); 

        /*
         * @brief setDealerId
         * @return
         * */
        void setDealerId(DATA_TYPES::CLIENT_ID dealerId);

        /**
         * @brief getLocationId
         * @return
         */
        long getLocationId() const;

        /**
         * @brief getOrderCategory
         * @return
         */
        DATA_TYPES::ENUM getOrderCategory() const;

    };


  }
}
#endif
